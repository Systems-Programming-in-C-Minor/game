#include "car/car_factory.hpp"
#include "car/player_car_behaviour.hpp"
#include <memory>
#include <scene.hpp>


std::shared_ptr<Car>
CarFactory::aiCar(const std::string &name, const std::string &tag, const std::string &sprite_path,
                  const std::shared_ptr<Scene>& scene) {
    return std::make_shared<Car>(name, tag, sprite_path, scene);
}

std::shared_ptr<Car>
CarFactory::playerCar(const std::string &name, const std::string &tag, const std::string &sprite_path,
                      const std::shared_ptr<Scene>& scene) {
    auto car = std::make_shared<Car>(name, tag, sprite_path, scene);
    auto behaviour = std::make_shared<PlayerCarBehaviour>(scene->get_event_manager());
    car->add_component(behaviour);

    return car;
}

std::shared_ptr<Car>
CarFactory::clientCar(const std::string &name, const std::string &tag, const std::string &sprite_path,
                      const std::shared_ptr<Scene>& scene) {
    return std::make_shared<Car>(name, tag, sprite_path, scene);
}
