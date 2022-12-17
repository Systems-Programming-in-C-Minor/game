#include "levels/level1_factory.hpp"
#include "track_factory.hpp"
#include "car/car_factory.hpp"
#include "checkpoint/checkpoint_factory.hpp"

Level Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    scene->gameobjects
            .push_back(TrackFactory::get("level1-track", "level1", "../assets/tracks/track1.png",
                                         "../assets/colliders/track1/track1_inner.xml",
                                         "../assets/colliders/track1/track1_outer.xml", scene));

    const std::vector<std::pair<Vector2d, Car::CarColor>> car_positions{
            {Vector2d{14, -76}, Car::CarColor::Red},
            {Vector2d{20, -72}, Car::CarColor::Blue},
            {Vector2d{26, -76}, Car::CarColor::Yellow},
            {Vector2d{31, -72}, Car::CarColor::Orange},
            {Vector2d{38, -76}, Car::CarColor::Pink},
            {Vector2d{43, -72}, Car::CarColor::Green},
    };

    std::vector<std::shared_ptr<Car>> cars;
    for (const auto car_position: car_positions) {
        auto car = CarFactory::base_car("player-car", car_position.second, car_position.first, scene);
        cars.push_back(car);
        scene->gameobjects.push_back(car);
    }

    const std::vector<CheckpointDef> check_pos{
            CheckpointDef{Vector2d{9.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{0.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-10.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-20.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-30.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-40.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-52.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-70.f, -56.f}, 30.f, 0.f},
            CheckpointDef{Vector2d{-55.f, -26.f}, 40.f, -45.f},
            CheckpointDef{Vector2d{-18.f, -8.f}, 30.f, -45.f},
            CheckpointDef{Vector2d{-7.f, 10.f}, 22.f, 0.f},
            CheckpointDef{Vector2d{-7.f, 16.f}, 22.f, 0.f},
            CheckpointDef{Vector2d{-18.f, 36.f}, 35.f, 60.f},
            CheckpointDef{Vector2d{-52.f, 36.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-65.f, 38.f}, 40.f, 45.f},
            CheckpointDef{Vector2d{-69.f, 50.f}, 32.f, 0.f},
            CheckpointDef{Vector2d{-69.f, 62.f}, 32.f, 0.f},
            CheckpointDef{Vector2d{-52.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{-40.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{-30.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{-20.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{-10.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{0.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{10.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{20.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{30.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{40.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{50.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{58.f, 73.f}, 23.f, 90.f},
            CheckpointDef{Vector2d{74.f, 62.f}, 30.f, 0.f},
            CheckpointDef{Vector2d{58.f, 48.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{48.f, 48.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{38.f, 48.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, 34.f}, 30.f, 0.f},
            CheckpointDef{Vector2d{16.f, 28.f}, 20.f, 0.f},
            CheckpointDef{Vector2d{14.f, 24.f}, 18.f, 0.f},
            CheckpointDef{Vector2d{14.f, 16.f}, 18.f, 0.f},
            CheckpointDef{Vector2d{14.f, 8.f}, 18.f, 0.f},
            CheckpointDef{Vector2d{14.f, 0.f}, 18.f, 0.f},
            CheckpointDef{Vector2d{15.f, -12.f}, 20.f, 0.f},
            CheckpointDef{Vector2d{16.f, -30.f}, 24.f, 0.f},
            CheckpointDef{Vector2d{28.f, -46.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{36.f, -46.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{51.f, -30.f}, 30.f, 0.f},
            CheckpointDef{Vector2d{44.f, -12.f}, 32.f, 45.f},
            CheckpointDef{Vector2d{36.f, 10.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{52.f, 25.f}, 22.f, 90.f},
            CheckpointDef{Vector2d{72.f, 20.f}, 30.f, 45.f},
            CheckpointDef{Vector2d{74.f, 6.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, 0.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -20.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -20.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -30.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -40.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -50.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{74.f, -60.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{62.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{50.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{40.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{30.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, -74.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{10.5f, -74.f}, 25.f, 90.f}
    };

    std::vector<std::shared_ptr<Checkpoint>> checkpoints;

    for (int index = 0; index < check_pos.size(); index++) {
        const bool is_finish = index >= check_pos.size() - 1;
        auto previous_checkpoint = checkpoints.empty() ? std::nullopt :
                                   std::make_optional<std::shared_ptr<Checkpoint>>(checkpoints[checkpoints.size() - 1]);
        auto checkpoint = CheckpointFactory::get(is_finish, previous_checkpoint, scene, check_pos[index]);
        checkpoints.emplace_back(checkpoint);
        scene->gameobjects.push_back(checkpoint);
    }

    return Level { cars, scene };
}
