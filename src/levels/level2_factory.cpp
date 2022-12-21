#include "levels/level2_factory.hpp"
#include "race/factories/checkpoint_factory.hpp"
#include "race/objects/car.hpp"
#include "colliders/track_factory.hpp"
#include "behaviours/game_behaviour.hpp"
#include "car/car_factory.hpp"
#include "overlay/fps_indicator_factory.hpp"
#include "objects/speed_boost_object.hpp"
#include <camera.hpp>
#include <components/text.hpp>
#include "components/audiosource.hpp"
#include "objects/debug_screen.hpp"
#include "utils/trigonometry.hpp"

RaceLevel Level2Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(std::make_shared<Camera>(4.f));

    scene->gameobjects
            .push_back(TrackFactory::get("level2-track", scene, "./assets/tracks/track2.png", 8.f));

    const auto un_engine = std::make_shared<GameObject>(
            "ad_board", "ad", Transform{Vector2d{-42.f, -104.f}, Vector2d{}, 0.f, 0.8f});
    un_engine->add_component(
            std::make_shared<Text>("Powered by UnEngine", "./assets/fonts/roboto/Roboto-Medium.ttf", 500, 10,
                                   Color{255, 255, 255, 0}, Color{0, 0, 0, 1}, 1));
    scene->gameobjects.push_back(un_engine);

    const std::vector<std::pair<Vector2d, CarColor>> car_positions{
            {Vector2d{-116, 14},  CarColor::Red},
            {Vector2d{-108, 10},  CarColor::Blue},
            {Vector2d{-116, 6},   CarColor::Yellow},
            {Vector2d{-108, 2},   CarColor::Green},
            {Vector2d{-116, -2},  CarColor::Orange},
            {Vector2d{-108, -6},  CarColor::Pink},
            {Vector2d{-116, -10}, CarColor::Purple},
            {Vector2d{-108, -14}, CarColor::Black},
    };

    std::vector<std::shared_ptr<Car>> cars;
    for (const auto car_position: car_positions) {
        auto car = CarFactory::get(car_position.second, car_position.first, scene);
        car->transform.set_angle(degrees_to_radians(0.f));
        cars.push_back(car);
        scene->gameobjects.push_back(car);
    }

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{75.f, 102.f}, 90.f, 200));
    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-86.f, 122.f}, 270.f, 200));
    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-20.f, -36.f}, 270.f, 200));

    const std::vector<Vector2d> targets{
            Vector2d{-60.f, -72.f},
            Vector2d{-74.f, -53.f},
            Vector2d{-60.f, -34.f},
            Vector2d{-10.f, -6.f},
            Vector2d{-13.f, 32.f},
            Vector2d{-65.f, 38.f},
            Vector2d{-72.f, 62.f},
            Vector2d{-52.f, 73.f},
            Vector2d{64.f, 73.f},
            Vector2d{77.f, 57.f},
            Vector2d{22.f, 37.f},
            Vector2d{16.f, -34.f},
            Vector2d{49.f, -39.f},
            Vector2d{34.f, 18.f},
            Vector2d{72.f, 20.f},
            Vector2d{73.f, -66.f}
    };

    const std::vector<CheckpointDef> check_pos{
            CheckpointDef{Vector2d{-110.f, 24.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 30.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 40.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 50.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 60.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 70.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 80.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 90.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 100.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-90.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-80.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-70.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-60.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-50.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-40.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-30.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-20.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-10.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{0.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{10.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{30.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{40.f, 116.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{60.f, 100.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 90.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 80.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 70.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 60.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 50.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{60.f, 40.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{40.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{30.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{10.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{0.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-10.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-20.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-30.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-50.f, 10.f}, 35.f, 0.f},
            CheckpointDef{Vector2d{-50.f, 0.f}, 35.f, 0.f},
            CheckpointDef{Vector2d{-50.f, -10.f}, 35.f, 0.f},
            CheckpointDef{Vector2d{-50.f, -20.f}, 35.f, 0.f},
            CheckpointDef{Vector2d{-30.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-20.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-10.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{0.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{10.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{30.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{40.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{50.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{60.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{70.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{80.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{90.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{100.f, -35.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{110.f, -50.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{110.f, -60.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{110.f, -70.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{110.f, -80.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{110.f, -90.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{100.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{90.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{80.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{70.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{60.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{50.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{40.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{30.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{20.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{10.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{0.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-10.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-20.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-30.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-40.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-50.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-60.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-70.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-80.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-90.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-100.f, -105.f}, 30.f, 90.f},
            CheckpointDef{Vector2d{-110.f, -90.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -80.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -70.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -60.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -50.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -40.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -30.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -20.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, -10.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 0.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 10.f}, 25.f, 0.f},
            CheckpointDef{Vector2d{-110.f, 20.f}, 25.f, 0.f},
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

    scene->gameobjects.push_back(std::make_shared<DebugScreenToWorld>(scene->get_event_manager()));

    scene->gameobjects.push_back(FpsIndicatorFactory::get(scene->get_event_manager()));

    scene->gameobjects.push_back(std::make_shared<GameBehaviour>(scene->get_event_manager(), cars, 1, 1));

    const auto background_music = std::make_shared<AudioSource>("./assets/audio/background2.mp3", false, true, 0.01,
                                                                "background");
    background_music->play();

    return RaceLevel{cars, targets, scene};
}
