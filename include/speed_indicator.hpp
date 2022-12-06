#ifndef GAME_SPEED_INDICATOR_HPP
#define GAME_SPEED_INDICATOR_HPP

#include "car.hpp"

class SpeedIndicator {
public:
    GameObject get(const std::string& name, const std::string& tag, Car& playerCar);
};

#endif //GAME_SPEED_INDICATOR_HPP
