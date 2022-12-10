#include "car_factory.hpp"

std::shared_ptr<Car> CarFactory::baseCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car> CarFactory::aiCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car> CarFactory::playerCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}

std::shared_ptr<Car> CarFactory::clientCar(const std::string &name, const std::string &tag, const std::string& sprite_path) {
    return std::make_shared<Car>(name, tag, sprite_path);
}
