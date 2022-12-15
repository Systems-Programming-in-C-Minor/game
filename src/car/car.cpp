#include "car/car.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "utils/trigonometry.hpp"
#include "components/colliders/boxcollider.hpp"
#include "checkpoint/checkpoint_behaviour.hpp"
#include <scene.hpp>

Car::Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene, const int order_in_layer)
        : GameObject(name, tag), CheckpointBehaviour(scene->get_event_manager()) {

    auto sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 1);
    add_component(sprite);

    auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, order_in_layer, BodyType::dynamic_body, Vector2d{16.f, -74.f}, 1.f);
    rigid_body->set_mass(1600.f);
    rigid_body->set_collider(collider);
    add_component(rigid_body);
    transform.set_scale(.5f);
    transform.set_angle(degrees_to_radians(90));
}
