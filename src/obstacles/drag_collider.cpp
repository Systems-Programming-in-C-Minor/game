#include "obstacles/drag_collider.hpp"
#include "car/car.hpp"
#include <components/colliders/chaincollider.hpp>
#include <scene.hpp>
#include <iostream>

DragCollider::DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                           float drag_modifier, float traction_modifier, float drive_force,
                           const std::vector<std::string> &drag_collider_paths)
        : GameObject(name, "drag-collider"), ColliderListener(event_manager), _drag_modifier(drag_modifier),
          _traction_modifier(traction_modifier), _drive_force(drive_force) {

    for (const auto &drag_collider_path: drag_collider_paths) {
        auto drag_collider = std::make_shared<ChainCollider>(drag_collider_path, true);
        auto drag_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
        drag_rigidbody->set_collider(drag_collider);
        add_component(drag_rigidbody);
    }
}

void DragCollider::on_collider_entry(const ColliderEntryEvent &event) {
    return;
    if (event.collider_a->game_object == this) {
        std::cout << event.is_touching << " try collide on " << event.collider_a->game_object->get_name() << std::endl;
        check_for_car(event.collider_b->game_object, true);
        return;
    }
    if (event.collider_b->game_object == this) {
        std::cout << event.is_touching << " try collide on " << event.collider_b->game_object->get_name() << std::endl;
        check_for_car(event.collider_a->game_object, true);
        return;
    }
}

void DragCollider::on_collider_exit(const ColliderExitEvent &event) {
    return;
    if (event.collider_a->game_object == this) {
        std::cout << event.is_touching << " try collide on " << event.collider_a->game_object->get_name() << std::endl;
        check_for_car(event.collider_b->game_object, false);
        return;
    }
    if (event.collider_b->game_object == this) {
        std::cout << event.is_touching << " try collide on " << event.collider_b->game_object->get_name() << std::endl;
        check_for_car(event.collider_a->game_object, false);
        return;
    }
}

void DragCollider::check_for_car(GameObject *game_object, bool collider_entry) {
    if (game_object->get_tag() != "car")
        return;
    auto car = reinterpret_cast<Car *>(game_object);
    auto friction = game_object->get_component<FrictionBehaviour>();

    if (collider_entry && std::find(applied_on.begin(), applied_on.end(), car) == applied_on.end()) {
        applied_on.emplace_back(car);

        friction->drag_modifier += _drag_modifier;
        friction->traction += _traction_modifier;
        car->max_drive_force -= _drive_force;

        return;
    }
    if (collider_entry || std::find(applied_on.begin(), applied_on.end(), car) == applied_on.end())
        return;

    friction->drag_modifier -= _drag_modifier;
    friction->traction -= _traction_modifier;
    car->max_drive_force += _drive_force;

    std::erase(applied_on, car);
}
