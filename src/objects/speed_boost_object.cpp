#include "objects/speed_boost_object.hpp"
#include "utils/trigonometry.hpp"
#include <components/rigidbody.hpp>
#include <components/colliders/boxcollider.hpp>
#include <components/sprite.hpp>
#include <scene.hpp>

SpeedBoostObject::SpeedBoostObject(EventManager &event_manager, const std::shared_ptr<Scene> &scene, Vector2d position,
                                   float angle, int tick_duration, float boost_force)
        : GameObject("speed-boost", "speed-boost"),
          ColliderListener(event_manager),
          _tick_duration(tick_duration),
          _boost_force(boost_force) {
    auto collider = std::make_shared<BoxCollider>(3.4f, 6.5f, true);
    auto body =
            std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, position, Color{ 255, 255, 255, 0 });
    body->set_collider(collider);
    add_component(body);

    transform.set_scale(1.3f);
    transform.set_angle(degrees_to_radians(angle));

    auto sprite = std::make_shared<Sprite>("./assets/other/speed-boost.png", 1, 100.f);
    add_component(sprite);
}

void SpeedBoostObject::on_collider_entry(const ColliderEntryEvent &event) {
    if (event.collider_a->game_object == this && event.collider_b->game_object->get_tag() == "car") {
        set_boost(reinterpret_cast<Car *>(event.collider_b->game_object));
    } else if (event.collider_b->game_object == this && event.collider_a->game_object->get_tag() == "car") {
        set_boost(reinterpret_cast<Car *>(event.collider_a->game_object));
    }

    if (event.collider_a->game_object == this || event.collider_b->game_object == this) {
        this->get_component<Sprite>()->set_color(Color{255, 255, 0, 200});
        _cars_on_booster++;
    }
}

void SpeedBoostObject::on_collider_exit(const ColliderExitEvent &event) {
    if (event.collider_a->game_object != this && event.collider_b->game_object != this)
        return;

    _cars_on_booster--;
    if (_cars_on_booster <= 0)
        this->get_component<Sprite>()->set_color(Color{255, 255, 255, 255});
}

void SpeedBoostObject::tick() {
    for (auto &car: _car_boosts) {
        car.second--;

        if (car.second == 0)
            remove_boost(car.first);
    }
}

void SpeedBoostObject::set_boost(Car *car) {
    auto car_boost = _car_boosts.find(car);
    if (car_boost == _car_boosts.end()) {
        _car_boosts.emplace(car, 0);
        car_boost = _car_boosts.find(car);
    }
    if (car_boost->second <= 0)
        apply_boost(car);

    car_boost->second = _tick_duration;
}

void SpeedBoostObject::apply_boost(Car *car) const {
    car->drive_force_multiplier += _boost_force;

}

void SpeedBoostObject::remove_boost(Car *car) const {
    car->drive_force_multiplier -= _boost_force;
}
