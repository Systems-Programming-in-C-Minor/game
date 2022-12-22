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
#include "objects/debug_draw_lines.hpp"
#include "objects/debug_screen.hpp"
#include "utils/trigonometry.hpp"
#include "colliders/void_collider.hpp"
#include "objects/debug_draw_target_factory.hpp"
#include "storage/json_properties.hpp"
#include "utils/high_score_reader.hpp"
#include "objects/high_score_ui_factory.hpp"

RaceLevel Level2Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(std::make_shared<Camera>(4.f), "level 2");
    std::shared_ptr<JsonProperties> high_score_properties = std::make_shared<JsonProperties>("high-scores.json");

    scene->gameobjects
            .push_back(TrackFactory::get("level2-track", scene, "./assets/tracks/track2.png", 8.f));

    const auto un_engine = std::make_shared<GameObject>(
            "ad_board", "ad", Transform{Vector2d{-42.f, -104.f}, Vector2d{}, 0.f, 0.8f});
    un_engine->add_component(
            std::make_shared<Text>("Powered by UnEngine", "./assets/fonts/roboto/Roboto-Medium.ttf", 500, 10,
                                   Color{255, 255, 255, 0}, Color{0, 0, 0, 1}, 1));
    scene->gameobjects.push_back(un_engine);

    scene->gameobjects.push_back(HighScoreUIFactory::get(get_high_score("level 2", high_score_properties), "level 2"));

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

    scene->gameobjects.push_back(std::make_shared<VoidCollider>(
            "void-inner_small",
            scene,
            scene->get_event_manager(),
            std::pair<std::string, std::string>
                    {
                            "./assets/colliders/track2/track2_inner_small_extra.xml",
                            "./assets/colliders/track2/track2_inner_small.xml"
                    }));

    scene->gameobjects.push_back(std::make_shared<VoidCollider>(
            "void-inner_large",
            scene,
            scene->get_event_manager(),
            std::pair<std::string, std::string>
                    {
                            "./assets/colliders/track2/track2_inner_large_extra.xml",
                            "./assets/colliders/track2/track2_inner_large.xml"
                    }));

    scene->gameobjects.push_back(std::make_shared<VoidCollider>(
            "void-collider-outer",
            scene,
            scene->get_event_manager(),
            std::pair<std::string, std::string>
                    {
                            "./assets/colliders/track2/track2_outer_extra.xml",
                            "./assets/colliders/track2/track2_outer.xml"
                    }));

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-86.f, 122.f}, 270.f, 200));
    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-20.f, -36.f}, 270.f, 200));
    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{94.f, -103.f}, 90.f, 200));

    const std::vector<Vector2d> targets{
            Vector2d{-115.f    ,     99.f},
            Vector2d{-89.f    ,     117.f},
            Vector2d{43.f    ,     116.f},
            Vector2d{60.f    ,     103.f},
            Vector2d{60.f    ,     30.f},
            Vector2d{-33.f    ,    23.f},
            Vector2d{-48.f    ,    11.f},
            Vector2d{-50.f    ,    -20.f},
            Vector2d{-29.f    ,    -35.f},
            Vector2d{100.f    ,    -35.f},
            Vector2d{111.f    ,    -44.f},
            Vector2d{111.f    ,    -99.f},
            Vector2d{13.f    ,    -103.f},
            Vector2d{-17.f    ,    -111.f},
            Vector2d{-63.f    ,    -111.f},
            Vector2d{-100.f    ,    -100.f},
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
            CheckpointDef{Vector2d{-90.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-80.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-70.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-60.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-50.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-40.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-30.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-20.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-10.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{0.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{10.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{20.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{30.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{40.f, 116.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{60.f, 100.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 90.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 80.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 70.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 60.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 50.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{60.f, 40.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{40.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{30.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{20.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{10.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{0.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-10.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-20.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-30.f, 24.f}, 25.f, 90.f},
            CheckpointDef{Vector2d{-50.f, 10.f}, 35.f, 180.f},
            CheckpointDef{Vector2d{-50.f, 0.f}, 35.f, 180.f},
            CheckpointDef{Vector2d{-50.f, -10.f}, 35.f, 180.f},
            CheckpointDef{Vector2d{-50.f, -20.f}, 35.f, 180.f},
            CheckpointDef{Vector2d{-30.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-20.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{-10.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{0.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{10.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{20.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{30.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{40.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{50.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{60.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{70.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{80.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{90.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{100.f, -35.f}, 25.f, 270.f},
            CheckpointDef{Vector2d{110.f, -50.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{110.f, -60.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{110.f, -70.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{110.f, -80.f}, 25.f, 180.f},
            CheckpointDef{Vector2d{110.f, -90.f}, 25.f, 180.f},
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

    DebugDrawTargetFactory(targets).get(*scene);

	const auto ui_debug_draw_ai_path = std::make_shared<DebugDrawLines>(targets);

    scene->gameobjects.push_back(ui_debug_draw_ai_path);

    scene->gameobjects.push_back(std::make_shared<DebugScreenToWorld>(scene->get_event_manager()));

    scene->gameobjects.push_back(FpsIndicatorFactory::get(scene->get_event_manager()));

    scene->gameobjects.push_back(std::make_shared<GameBehaviour>(scene->get_event_manager(), cars));

    const auto background_music = std::make_shared<AudioSource>("./assets/audio/background2.mp3", false, true, 0.01,
                                                                "background");
    background_music->play();

    return RaceLevel{cars, targets, scene};
}
