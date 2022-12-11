#include "car/car.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "utils/trigonometry.hpp"
#include "components/colliders/boxcollider.hpp"

Car::Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene)
        : GameObject(name, tag) {
    auto sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 1);
    add_component(sprite);

    auto collider = std::make_shared<BoxCollider>(4.f, 4.f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, BodyType::dynamic_body, Vector2d{0.86f, -4.64f}, 1.f);
    rigid_body->set_collider(collider);
    add_component(rigid_body);
    transform.set_scale(0.03f);
    transform.set_angle(degrees_to_radians(90));
}

int Car::get_current_round() const {
    return _current_round;
}

float Car::get_current_speed() const {
    return _current_speed;
}
