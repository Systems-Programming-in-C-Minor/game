#include "car/car_factory.hpp"
#include "car/player_car_behaviour.hpp"
#include <memory>

std::shared_ptr<Car> CarFactory::baseCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car> CarFactory::aiCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car> CarFactory::playerCar(const std::string &name, const std::string &tag, const std::string& sprite_path, EventManager &event_manager) {
    auto car = std::make_shared<Car>(name, tag, sprite_path);
    auto behaviour = std::make_shared<PlayerCarBehaviour>(event_manager);
    car->add_component(behaviour);
    return car;
}

std::shared_ptr<Car> CarFactory::clientCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}
