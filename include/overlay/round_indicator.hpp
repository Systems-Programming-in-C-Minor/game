#ifndef GAME_ROUND_INDICATOR_HPP
#define GAME_ROUND_INDICATOR_HPP

#include "race/objects/car.hpp"

class RoundIndicator {
public:
    std::shared_ptr<GameObject> get(const std::string& name, const std::string& tag, Car& playerCar);
};

#endif //GAME_ROUND_INDICATOR_HPP
