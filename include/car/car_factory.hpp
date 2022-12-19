
#ifndef GAME_CAR_FACTORY_HPP
#define GAME_CAR_FACTORY_HPP

#include <race/objects/car.hpp>

enum CarColor {
    Red,
    Blue,
    Yellow,
    Green,
    Orange,
    Pink,
    Purple,
    Black
};

class CarFactory {
public:
    static std::shared_ptr<Car>
    get(const std::string &name, CarColor color, Vector2d position, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_CAR_FACTORY_HPP
