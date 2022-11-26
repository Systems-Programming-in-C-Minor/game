#include "car_factory.hpp"

Car CarFactory::baseCar(const std::string& name, const std::string& tag, const std::string sprite_path) {
    return Car(name, tag, sprite_path);
}

Car CarFactory::aiCar(const std::string& name, const std::string& tag, const std::string sprite_path) {
    return Car(name, tag, sprite_path);
}

Car CarFactory::playerCar(const std::string& name, const std::string& tag, const std::string sprite_path) {
    return Car(name, tag, sprite_path);
}

Car CarFactory::clientCar(const std::string& name, const std::string& tag, const std::string sprite_path) {
    return Car(name, tag, sprite_path);
}
