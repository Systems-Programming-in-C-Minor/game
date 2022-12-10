#include "levels/level1_factory.hpp"
#include "track_factory.hpp"
#include "car/car_factory.hpp"

std::shared_ptr<Scene> Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    scene->gameobjects
            .push_back(TrackFactory::get("level1-track", "level1", "../assets/tracks/track1.png"));

    scene->gameobjects.push_back(CarFactory::playerCar("player-car", "car", "../assets/cars/red_car.png", scene));

    return scene;
}
