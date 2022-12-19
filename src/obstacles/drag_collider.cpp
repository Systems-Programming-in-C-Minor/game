#include "obstacles/drag_collider.hpp"
#include "race/objects/car.hpp"
#include <components/colliders/chaincollider.hpp>
#include <scene.hpp>
#include <iostream>

DragCollider::DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                           float drag_modifier, float traction_modifier, float drive_force,
                           const std::pair<std::string, std::string> &drag_collider_paths)
        : GameObject(name, "drag-collider"), ColliderListener(event_manager), _drag_modifier(drag_modifier),
          _traction_modifier(traction_modifier), _drive_force(drive_force) {

    auto drag_collider_inner = std::make_shared<ChainCollider>(drag_collider_paths.first, true);
    auto drag_rigidbody_inner = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f},
                                                            1.0f);
    drag_rigidbody_inner->set_collider(drag_collider_inner);
    add_component(drag_rigidbody_inner);

    auto drag_collider_outer = std::make_shared<ChainCollider>(drag_collider_paths.second, true);
    auto drag_rigidbody_outer = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f},
                                                            1.0f);
    drag_rigidbody_outer->set_collider(drag_collider_outer);
    add_component(drag_rigidbody_outer);
    _inner_body = drag_rigidbody_inner.get();
    _outer_body = drag_rigidbody_outer.get();
}

void DragCollider::on_collider_entry(const ColliderEntryEvent &event) {
    if (event.collider_a->game_object == this && event.collider_b->game_object->get_tag() == "car") {
        toggle_drag_on_car(event.collider_a, reinterpret_cast<Car *>(event.collider_b->game_object), true);
        return;
    }
    if (event.collider_b->game_object == this && event.collider_a->game_object->get_tag() == "car") {
        toggle_drag_on_car(event.collider_b, reinterpret_cast<Car *>(event.collider_a->game_object), true);
        return;
    }
}

void DragCollider::on_collider_exit(const ColliderExitEvent &event) {
    if (event.collider_a->game_object == this && event.collider_b->game_object->get_tag() == "car") {
        toggle_drag_on_car(event.collider_a, reinterpret_cast<Car *>(event.collider_b->game_object), false);
        return;
    }
    if (event.collider_b->game_object == this && event.collider_a->game_object->get_tag() == "car") {
        toggle_drag_on_car(event.collider_b, reinterpret_cast<Car *>(event.collider_a->game_object), false);
        return;
    }
}

void DragCollider::toggle_drag_on_car(RigidBody *body, Car *car, bool collider_entry) {

    if (body == _outer_body) {
        _collided_outer = collider_entry;
        std::cout << "inner " << _collided_inner << " outer " << _collided_outer << " appllied " << _drag_applied
                  << std::endl;

        if (!_collided_inner && !collider_entry) {
            remove_drag(car);
            std::cout << "inner " << _collided_inner << " outer " << _collided_outer << " appllied " << _drag_applied
                      << std::endl;
            return;
        }
        return;
    }
    if (body != _inner_body)
        return;

    _collided_inner = collider_entry;

    if (_collided_inner && _collided_outer) {
        apply_drag(car);
    }

    if (_collided_outer && !collider_entry) {
        remove_drag(car);
        std::cout << "inner " << _collided_inner << " outer " << _collided_outer << " appllied " << _drag_applied
                  << std::endl;
        return;
    }

    std::cout << "inner " << _collided_inner << " outer " << _collided_outer << " appllied " << _drag_applied
              << std::endl;
}

void DragCollider::apply_drag(Car *car) {
    if (_drag_applied)
        return;

    auto friction = car->get_component<FrictionBehaviour>();
    _drag_applied = true;
    friction->drag_modifier += _drag_modifier;
    friction->traction += _traction_modifier;
    car->max_drive_force += _drive_force;
}

void DragCollider::remove_drag(Car *car) {
    if (!_drag_applied)
        return;

    auto friction = car->get_component<FrictionBehaviour>();
    _drag_applied = false;
    friction->drag_modifier -= _drag_modifier;
    friction->traction -= _traction_modifier;
    car->max_drive_force -= _drive_force;
}
