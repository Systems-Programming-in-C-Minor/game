#include "car/car_factory.hpp"
#include "car/player_car_behaviour.hpp"
#include <memory>
#include <scene.hpp>
#include <components/rigidbody.hpp>

std::shared_ptr<Car>
CarFactory::baseCar(const std::string &name, const std::string &tag, const std::string &sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car>
CarFactory::aiCar(const std::string &name, const std::string &tag, const std::string &sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car>
CarFactory::playerCar(const std::string &name, const std::string &tag, const std::string &sprite_path,
                      const std::shared_ptr<Scene>& scene) {
    auto car = std::make_shared<Car>(name, tag, sprite_path);
    auto behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(behaviour);

    Vector2d vec{1, 1};
    auto body = std::make_shared<RigidBody>(*scene, BodyType::kinematic_body, vec, 1.f);
    car->add_component(body);

    return car;
}

std::shared_ptr<Car>
CarFactory::clientCar(const std::string &name, const std::string &tag, const std::string &sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}
