#include "levels/level1_factory.hpp"
#include "track_factory.hpp"
#include "car/car_factory.hpp"
#include "checkpoint_factory.hpp"

std::shared_ptr<Scene> Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    scene->gameobjects
            .push_back(TrackFactory::get("level1-track", "level1", "../assets/tracks/track1.png",
                                         "../assets/colliders/track1/track1_inner.xml",
                                         "../assets/colliders/track1/track1_outer.xml", scene));

    scene->gameobjects.push_back(CarFactory::playerCar("player-car", "car", "../assets/cars/red_car.png", scene));


    std::vector<Vector2d> checkpoint_positions;
    {
        checkpoint_positions.emplace_back(-13.f, 32.f);
        checkpoint_positions.emplace_back(-65.f, 38.f);
        checkpoint_positions.emplace_back(-72.f, 62.f);
        checkpoint_positions.emplace_back(-52.f, 73.f);
        checkpoint_positions.emplace_back(64.f, 73.f);
        checkpoint_positions.emplace_back(77.f, 57.f);
        checkpoint_positions.emplace_back(22.f, 37.f);
        checkpoint_positions.emplace_back(16.f, -34.f);
        checkpoint_positions.emplace_back(49.f, -39.f);
        checkpoint_positions.emplace_back(34.f, 18.f);
        checkpoint_positions.emplace_back(72.f, 20.f);
        checkpoint_positions.emplace_back(73.f, -66.f);
        checkpoint_positions.emplace_back(-60.f, -72.f);
        checkpoint_positions.emplace_back(-74.f, -53.f);
        checkpoint_positions.emplace_back(-60.f, -34.f);
        checkpoint_positions.emplace_back(-10.f, -6.f);
    }

    std::vector<std::shared_ptr<Checkpoint>> checkpoints;

    for (int index = 0; index < checkpoint_positions.size(); index++) {
        const bool is_finish = index >= checkpoint_positions.size() - 1;
        auto previous_checkpoint = checkpoints.empty() ? std::nullopt :
                                   std::make_optional<std::shared_ptr<Checkpoint>>(checkpoints[checkpoints.size()]);
        auto checkpoint = CheckpointFactory::get(is_finish, previous_checkpoint, checkpoint_positions[index], scene);
    }

    for (const auto& checkpoint : checkpoints) {
        scene->gameobjects.push_back(checkpoint);
    }

    return scene;
}
