#include "levels/level.hpp"

Level::Level(const std::vector<std::shared_ptr<Car>> cars, std::vector<Vector2d> targets,
             const std::shared_ptr<Scene> scene) : scene(scene), targets(targets), cars(cars) {}
