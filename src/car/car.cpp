#include "car/car.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "utils/trigonometry.hpp"
#include "components/colliders/boxcollider.hpp"
#include "checkpoint/checkpoint_behaviour.hpp"
#include <scene.hpp>

Car::Car(const std::string &name, CarColor color, const Vector2d position, const std::shared_ptr<Scene> &scene)
        : GameObject(name, "car"), CheckpointBehaviour(scene->get_event_manager()) {

    const std::map<CarColor, std::string> sprites{
            {Blue, "./assets/cars/blue_car.png"},
            {Red, "./assets/cars/red_car.png"},
            {Yellow, "./assets/cars/yellow_car.png"},
            {Green, "./assets/cars/green_car.png"},
            {Orange, "./assets/cars/orange_car.png"},
            {Pink, "./assets/cars/pink_car.png"},
    };

    auto sprite = std::make_shared<Sprite>(sprites.at(color), Color(0, 0, 0, 0), false, false, 1, 1);
    add_component(sprite);

    auto collider = std::make_shared<BoxCollider>(1.65f, 4.f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, 1000, BodyType::dynamic_body, position, 1.f);
    rigid_body->set_mass(1600.f);
    rigid_body->set_collider(collider);
    add_component(rigid_body);
    transform.set_scale(.5f);
    transform.set_angle(degrees_to_radians(90.f));
}
