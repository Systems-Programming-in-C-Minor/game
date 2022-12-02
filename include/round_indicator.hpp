#ifndef GAME_ROUND_INDICATOR_HPP
#define GAME_ROUND_INDICATOR_HPP

#include "uiobjects/text.hpp"
#include "car.hpp"

class RoundIndicator {
public:
    GameObject get(const std::string& name, const std::string& tag, Car& playerCar);
};

#endif //GAME_ROUND_INDICATOR_HPP
