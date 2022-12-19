#include "obstacles/drag_collider.hpp"
#include "car/car.hpp"
#include <components/colliders/chaincollider.hpp>
#include <scene.hpp>

DragCollider::DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene,
                           float drag_modifier, const std::vector<std::string> &drag_collider_paths)
        : GameObject(name, "drag-collider"), ColliderListener(scene->get_event_manager()),
          _drag_modifier(drag_modifier) {

    for (const auto &drag_collider_path: drag_collider_paths) {
        auto drag_collider = std::make_shared<ChainCollider>(drag_collider_path, true);
        auto drag_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
        drag_rigidbody->set_collider(drag_collider);
        add_component(drag_rigidbody);
    }
}

void DragCollider::on_collider_entry(const ColliderEntryEvent &event) {
    if (event.collider_a->game_object == this) {
        check_for_car(event.collider_b->game_object, true);
        return;
    }
    if (event.collider_b->game_object == this) {
        check_for_car(event.collider_a->game_object, true);
        return;
    }
}

void DragCollider::on_collider_exit(const ColliderExitEvent &event) {
    if (event.collider_a->game_object == this) {
        check_for_car(event.collider_b->game_object, false);
        return;
    }
    if (event.collider_b->game_object == this) {
        check_for_car(event.collider_a->game_object, false);
        return;
    }
}

void DragCollider::check_for_car(GameObject *game_object, bool enter_collider) const {
    if (game_object->get_tag() != "car")
        return;
    auto friction = game_object->get_component<FrictionBehaviour>();

    enter_collider ? friction->drag_modifier += _drag_modifier : friction->drag_modifier -= _drag_modifier;
}