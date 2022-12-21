#include "colliders/void_collider.hpp"
#include "race/objects/car.hpp"
#include <components/colliders/chaincollider.hpp>
#include <scene.hpp>
#include <race/behaviours/checkpoint_behaviour.hpp>
#include <race/objects/checkpoint.hpp>
#include <components/sprite.hpp>

VoidCollider::VoidCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                           const std::pair<std::string, std::string> &drag_collider_paths)
        : GameObject(name, "void-collider"), ColliderListener(event_manager) {

    auto drag_collider_inner = std::make_shared<ChainCollider>(drag_collider_paths.first, true);
    auto drag_rigidbody_inner =
            std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, Color{ 255, 255, 255, 0 });
    drag_rigidbody_inner->set_collider(drag_collider_inner);
    add_component(drag_rigidbody_inner);

    auto drag_collider_outer = std::make_shared<ChainCollider>(drag_collider_paths.second, true);
    auto drag_rigidbody_outer = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f},
        Color{ 255, 255, 255, 0 });
    drag_rigidbody_outer->set_collider(drag_collider_outer);
    add_component(drag_rigidbody_outer);
    _inner_body = drag_rigidbody_inner.get();
    _outer_body = drag_rigidbody_outer.get();
}

void VoidCollider::on_collider_entry(const ColliderEntryEvent &event) {
    if (event.collider_a->game_object == this && event.collider_b->game_object->get_tag() == "car") {
        toggle_collided(event.collider_a, reinterpret_cast<Car *>(event.collider_b->game_object), true);
        return;
    }
    if (event.collider_b->game_object == this && event.collider_a->game_object->get_tag() == "car") {
        toggle_collided(event.collider_b, reinterpret_cast<Car *>(event.collider_a->game_object), true);
        return;
    }
}

void VoidCollider::on_collider_exit(const ColliderExitEvent &event) {
    if (event.collider_a->game_object == this && event.collider_b->game_object->get_tag() == "car") {
        toggle_collided(event.collider_a, reinterpret_cast<Car *>(event.collider_b->game_object), false);
        return;
    }
    if (event.collider_b->game_object == this && event.collider_a->game_object->get_tag() == "car") {
        toggle_collided(event.collider_b, reinterpret_cast<Car *>(event.collider_a->game_object), false);
        return;
    }
}

void VoidCollider::toggle_collided(RigidBody *body, Car *car, bool collider_entry) {
    auto void_ite = _car_voids.find(car);
    if (void_ite == _car_voids.end()) {
        _car_voids.emplace(car, std::make_shared<VoidObject>(car->transform.get_scale()));
        void_ite = _car_voids.find(car);
    }
    auto void_object = void_ite->second;

    if (body == _outer_body) {
        void_object->collided_outer = collider_entry;

        if (!void_object->collided_inner && !collider_entry && void_object->enter_void < 0) {
            void_object->enter_void = tick_duration;
            return;
        }
        return;
    }
    if (body != _inner_body)
        return;

    void_object->collided_inner = collider_entry;
}

void VoidCollider::spawn_back(Car *car) {
    auto checkpoint = car->get_component<CheckpointBehaviour>()->get_last_touched();
    if (checkpoint.has_value()) {
        car->transform.set_position(checkpoint.value()->transform.get_position());
        car->transform.set_angle(checkpoint.value()->transform.get_angle());
    }
}

void VoidCollider::tick() {
    GameObject::tick();

    for (auto &car: _car_voids) {
        if (car.second->enter_void >= 0) {
            if (car.second->enter_void == tick_duration) {
                car.first->is_enabled = false;
            }
            car.first->transform.set_scale(car.first->transform.get_scale() - (car.second->scale / (float) tick_duration));
            car.first->transform.set_angle(car.first->transform.get_angle() + 0.1f);
            car.second->enter_void--;
            if (car.second->enter_void == 0) {
                spawn_back(car.first);
                car.first->transform.set_scale(car.second->scale);
                car.first->is_enabled = true;
            }
        }
    }
}

VoidCollider::VoidObject::VoidObject(float scale) : scale(scale) {}
