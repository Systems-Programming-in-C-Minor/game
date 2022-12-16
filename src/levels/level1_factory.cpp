#include "levels/level1_factory.hpp"
#include "track_factory.hpp"
#include "car/car_factory.hpp"
#include "checkpoint/checkpoint_factory.hpp"
#include "tree_factory.hpp"
#include <utils/random.hpp>

std::shared_ptr<Scene> Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    scene->gameobjects
            .push_back(TrackFactory::get("level1-track", "level1", "../assets/tracks/track1.png",
                                         "../assets/colliders/track1/track1_inner.xml",
                                         "../assets/colliders/track1/track1_outer.xml", scene));

    scene->gameobjects.push_back(CarFactory::playerCar("player-car", "car", "../assets/cars/red_car.png", scene));


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

    const std::vector<std::pair<std::pair<Vector2d, Vector2d>, std::pair<TreeFactory::TreeType, int>>> tree_boxes{
            std::pair{std::pair{Vector2d{-80.f, 0.f}, Vector2d{-30.f, 20.f}}, std::pair{TreeFactory::Tree1, 200}},
            std::pair{std::pair{Vector2d{-80.f, -10.f}, Vector2d{-50.f, 0.f}}, std::pair{TreeFactory::Tree1, 60}},
            std::pair{std::pair{Vector2d{-45.f, -60.f}, Vector2d{0.f, -40.f}}, std::pair{TreeFactory::Tree2, 80}},
            std::pair{std::pair{Vector2d{-20.f, -40.f}, Vector2d{0.f, -35.f}}, std::pair{TreeFactory::Tree2, 10}},
            std::pair{std::pair{Vector2d{-52.f, 52.f}, Vector2d{8.f, 62.f}}, std::pair{TreeFactory::Tree1, 140}},
    };

    for (const auto tree_box: tree_boxes) {
        for (int index = 0; index < tree_box.second.second; index++) {
            scene->gameobjects.push_back(TreeFactory::get(tree_box.second.first, Vector2d{
                    static_cast<float>(Random::random(tree_box.first.second.x, tree_box.first.first.x)),
                    static_cast<float>(Random::random(tree_box.first.second.y, tree_box.first.first.y))}));
        }
    }

    return scene;
}
