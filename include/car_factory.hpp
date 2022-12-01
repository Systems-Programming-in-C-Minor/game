#ifndef GAME_CAR_FACTORY_HPP
#define GAME_CAR_FACTORY_HPP

#include "car.hpp"
#include "string"

class CarFactory {
public:
    Car aiCar(const std::string& name, const std::string& tag, const std::string sprite_path);
    Car playerCar(const std::string& name, const std::string& tag, const std::string sprite_path);
    Car clientCar(const std::string& name, const std::string& tag, const std::string sprite_path);
protected:
    Car baseCar(const std::string& name, const std::string& tag, const std::string sprite_path);
};

#endif //GAME_CAR_FACTORY_HPP
