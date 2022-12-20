#include "objects/speed_boost_object.hpp"
#include "utils/trigonometry.hpp"
#include <components/rigidbody.hpp>
#include <components/colliders/boxcollider.hpp>
#include <components/sprite.hpp>
#include <scene.hpp>

SpeedBoostObject::SpeedBoostObject(EventManager &event_manager, const std::shared_ptr<Scene> &scene, Vector2d position, float angle, int tick_duration)
        :
        GameObject("speed-boost", "speed-boost"),
        ColliderListener(event_manager),
        _tick_duration(tick_duration) {
    auto collider = std::make_shared<BoxCollider>(3.4f, 6.5f, true);
    auto body =
            std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, position, 1.0f);
    body->set_collider(collider);
    add_component(body);

    transform.set_angle(degrees_to_radians(angle));


    auto sprite = std::make_shared<Sprite>("./assets/other/speed-boost.png", 20, 100.f);
    add_component(sprite);
}

void SpeedBoostObject::on_collider_entry(const ColliderEntryEvent &event) {

}

void SpeedBoostObject::tick() {

}
