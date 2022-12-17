
#ifndef GAME_LEVEL_HPP
#define GAME_LEVEL_HPP

#include "car/car.hpp"
#include <memory>

class Level {
public:
    Level(std::vector<std::shared_ptr<Car>> cars, std::vector<Vector2d> targets,
          std::shared_ptr<Scene> scene);

    const std::vector<Vector2d> targets;
    const std::vector<std::shared_ptr<Car>> cars;
    const std::shared_ptr<Scene> scene;
};

#endif //GAME_LEVEL_HPP