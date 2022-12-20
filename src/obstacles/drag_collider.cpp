#include "obstacles/drag_collider.hpp"
#include "race/objects/car.hpp"
#include <components/colliders/chaincollider.hpp>
#include <scene.hpp>
#include <iostream>

DragCollider::DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                           float traction_modifier, float drive_force,
                           const std::pair<std::string, std::string> &drag_collider_paths)
        : GameObject(name, "drag-collider"), ColliderListener(event_manager), _traction_modifier(traction_modifier),
          _drive_force(drive_force) {

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
    auto drag_ite = _car_drags.find(car);
    if (drag_ite == _car_drags.end()) {
        _car_drags.emplace(car, std::make_shared<DragObject>());
        drag_ite = _car_drags.find(car);
    }
    auto drag = drag_ite->second;


    if (body == _outer_body) {
        drag->_collided_outer = collider_entry;

        if (!drag->_collided_inner && !collider_entry) {
            remove_drag(car, drag);
            return;
        }
        return;
    }
    if (body != _inner_body)
        return;

    drag->_collided_inner = collider_entry;

    if (drag->_collided_inner && drag->_collided_outer) {
        apply_drag(car, drag);
    }

    if (drag->_collided_outer && !collider_entry) {
        remove_drag(car, drag);
        return;
    }
}

void DragCollider::apply_drag(Car *car, const std::shared_ptr<DragObject> &drag) const {
    if (drag->_drag_applied)
        return;

    auto friction = car->get_component<FrictionBehaviour>();
    drag->_drag_applied = true;
    friction->traction += _traction_modifier;
    car->max_drive_force += _drive_force;
}

void DragCollider::remove_drag(Car *car, const std::shared_ptr<DragObject> &drag) const {
    if (!drag->_drag_applied)
        return;

    auto friction = car->get_component<FrictionBehaviour>();
    drag->_drag_applied = false;
    friction->traction -= _traction_modifier;
    car->max_drive_force -= _drive_force;
}
