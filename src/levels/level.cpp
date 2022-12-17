#include "levels/level.hpp"

Level::Level(const std::vector<std::shared_ptr<Car>> cars, const std::shared_ptr<Scene> scene) : scene(scene), cars(cars) {}
