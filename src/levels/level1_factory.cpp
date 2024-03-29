#include "levels/level1_factory.hpp"
#include "race/factories/checkpoint_factory.hpp"
#include "race/objects/car.hpp"
#include "background/tree_factory.hpp"
#include "colliders/track_factory.hpp"
#include "colliders/guardrail_factory.hpp"
#include "colliders/tire_stack_factory.hpp"
#include "colliders/drag_collider.hpp"
#include "behaviours/game_behaviour.hpp"
#include "car/car_factory.hpp"
#include "overlay/fps_indicator_factory.hpp"
#include "objects/speed_boost_object.hpp"
#include <utils/random.hpp>
#include <camera.hpp>
#include <components/text.hpp>

#include "background/background_factory.hpp"
#include "components/audiosource.hpp"
#include "objects/debug_draw_lines.hpp"
#include "objects/debug_draw_target_factory.hpp"
#include "objects/debug_screen.hpp"
#include "utils/high_score_reader.hpp"
#include "objects/high_score_ui_factory.hpp"
#include <objects/debug_screen.hpp>


RaceLevel Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(std::make_shared<Camera>(5.f), "level 1");
    std::shared_ptr<JsonProperties> high_score_properties = std::make_shared<JsonProperties>("high-scores.json");

    scene->gameobjects
            .push_back(TrackFactory::get("level1-track",
                                         scene,
                                         "./assets/tracks/track1.png",
                                         12.f,
                                         {"./assets/colliders/track1/track1_inner.xml"},
                                         "./assets/colliders/track1/track1_outer.xml"
            ));

    const auto un_engine = std::make_shared<GameObject>(
            "ad_board", "ad", Transform{Vector2d{0.f, 66.9f}, Vector2d{}, 0.f, 0.8f});
    un_engine->add_component(
            std::make_shared<Text>("Powered by UnEngine", "./assets/fonts/roboto/Roboto-Medium.ttf", 620, 1,
                                   Color{255, 255, 255, 170}, Color{0, 0, 0, 1}, 1));
    scene->gameobjects.push_back(un_engine);

    scene->gameobjects.push_back(HighScoreUIFactory::get(get_high_score("level 1", high_score_properties), "level 1"));

    scene->gameobjects.push_back(std::make_shared<DragCollider>(
            "grass-collider-inner",
            scene,
            scene->get_event_manager(),
            1.f,
            std::pair<std::string, std::string>
                    {"./assets/colliders/track1/track1_grass_inner_inside.xml",
                     "./assets/colliders/track1/track1_grass_inner.xml"}));


    scene->gameobjects.push_back(std::make_shared<DragCollider>(
            "grass-collider-outer",
            scene,
            scene->get_event_manager(),
            1.f,
            std::pair<std::string, std::string>
                    {"./assets/colliders/track1/track1_grass_outer_inside.xml",
                     "./assets/colliders/track1/track1_grass_outer.xml"}));

    const std::vector<std::pair<Vector2d, CarColor>> car_positions{
            {Vector2d{14, -76}, CarColor::Red},
            {Vector2d{20, -72}, CarColor::Blue},
            {Vector2d{26, -76}, CarColor::Yellow},
            {Vector2d{31, -72}, CarColor::Green},
            {Vector2d{38, -76}, CarColor::Orange},
            {Vector2d{43, -72}, CarColor::Pink},
            {Vector2d{50, -76}, CarColor::Purple},
            {Vector2d{55, -72}, CarColor::Black},
    };

    std::vector<std::shared_ptr<Car>> cars;
    for (const auto car_position: car_positions) {
        auto car = CarFactory::get(car_position.second, car_position.first, scene);
        cars.push_back(car);
        scene->gameobjects.push_back(car);
    }

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-53.4f, -25.7}, 300.f, 30));

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{-50.f, 73.f}, 270.f, 50));

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{13.4f, 24.1}, 180.f, 30));

    scene->gameobjects.push_back(
            std::make_shared<SpeedBoostObject>(scene->get_event_manager(), scene, Vector2d{76.4f, 12.1f}, 180.f, 50));

    const std::vector<Vector2d> targets{
        Vector2d{-59.f	,	-74.f},
        Vector2d{-74.f	, 	-53.f},
        Vector2d{-61.f	, 	-33.f},
        Vector2d{-9.f	, 	-7.f},
        Vector2d{-6.f	, 	25.f},
        Vector2d{-20.f	, 	36.f},
        Vector2d{-57.f	, 	37.f},
        Vector2d{-74.f	, 	53.f},
        Vector2d{-67.f	, 	68.f},
        Vector2d{-50.f	, 	74.f},
        Vector2d{63.f	, 	74.f},
        Vector2d{74.f	, 	58.f},
        Vector2d{65.f	, 	44.f},
        Vector2d{31.f	, 	44.f},
        Vector2d{16.f	, 	27.f},
        Vector2d{16.f	, 	-29.f},
        Vector2d{37.f	, 	-49.f},
        Vector2d{54.f	, 	-30.f},
        Vector2d{33.f	, 	9.f},
        Vector2d{41.f	, 	24.f},
        Vector2d{67.f	, 	25.f},
        Vector2d{74.f	, 	16.f},
        Vector2d{74.f	, 	-60.f},
        Vector2d{63.f	, 	-74.f}
    };

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
            std::pair{std::pair{Vector2d{-80.f, 0.f}, Vector2d{-30.f, 20.f}}, std::pair{TreeFactory::Tree1, 50}},
            std::pair{std::pair{Vector2d{-80.f, -10.f}, Vector2d{-50.f, 0.f}}, std::pair{TreeFactory::Tree1, 15}},
            std::pair{std::pair{Vector2d{-45.f, -60.f}, Vector2d{0.f, -40.f}}, std::pair{TreeFactory::Tree2, 20}},
            std::pair{std::pair{Vector2d{-20.f, -40.f}, Vector2d{0.f, -35.f}}, std::pair{TreeFactory::Tree2, 6}},
            std::pair{std::pair{Vector2d{-52.f, 52.f}, Vector2d{8.f, 62.f}}, std::pair{TreeFactory::Tree1, 35}},
    };

    for (const auto tree_box: tree_boxes) {
        for (int index = 0; index < tree_box.second.second; index++) {
            scene->gameobjects.push_back(TreeFactory::get(tree_box.second.first, Vector2d{
                    static_cast<float>(Random::random(tree_box.first.second.x, tree_box.first.first.x)),
                    static_cast<float>(Random::random(tree_box.first.second.y, tree_box.first.first.y))}));
        }
    }

    const std::vector<std::pair<const Vector2d, float>> guard_rails{
            std::pair(Vector2d{-50, 28}, 0.f),
            std::pair(Vector2d{-35, 28}, 0.f),
            std::pair(Vector2d{-60, -45}, 60.f),
            std::pair(Vector2d{12, -50}, -45.f),
            std::pair(Vector2d{-10, -67}, 0.f),
            std::pair(Vector2d{0, -67}, 0.f),
            std::pair(Vector2d{10, -67}, 0.f),
            std::pair(Vector2d{64, 61}, 90.f),
            std::pair(Vector2d{-60, 56}, 100.f),
            std::pair(Vector2d{-62, -60}, 100.f),
            std::pair(Vector2d{-56, -66}, -20.f),
    };

    for (const auto guard_rail: guard_rails) {
        scene->gameobjects.push_back(GuardrailFactory::get(guard_rail.first, guard_rail.second, scene));
    }

    const std::vector<Vector2d> tire_stacks{
            Vector2d{-58, 50},
            Vector2d{-56, 49},
            Vector2d{-17, 26},
            Vector2d{-16, 24},
            Vector2d{-15, 22},
            Vector2d{-14, 20},
            Vector2d{-14, 18},
            Vector2d{-14, 16},
            Vector2d{-14, 14},
            Vector2d{-14, 12},
            Vector2d{-16, -1},
            Vector2d{-18, -2},
            Vector2d{-20, -3},
            Vector2d{-22, -4},
            Vector2d{-24, -5},
            Vector2d{-26, -6},
            Vector2d{-28, -7},
            Vector2d{-30, -8},
    };

    for (const auto tire_stack: tire_stacks) {
        scene->gameobjects.push_back(TireStackFactory::get(tire_stack, scene));
    }

    DebugDrawTargetFactory(targets, 8.f).get(*scene);

    const auto ui_debug_draw_ai_path = std::make_shared<DebugDrawLines>(targets);
    scene->gameobjects.push_back(std::make_shared<DebugScreenToWorld>(scene->get_event_manager()));

    scene->gameobjects.push_back(ui_debug_draw_ai_path);

	scene->gameobjects.push_back(std::make_shared<DebugScreenToWorld>(scene->get_event_manager()));

    scene->gameobjects.push_back(FpsIndicatorFactory::get(scene->get_event_manager()));

    scene->gameobjects.push_back(std::make_shared<GameBehaviour>(scene->get_event_manager(), cars));

    const auto background_music =
            std::make_shared<AudioSource>("./assets/audio/background1.mp3", false, true, 0.05, "background");

    background_music->play();

	const std::vector<std::string> paths = {
				"./assets/tracks/track1_bg_1.png",
                "./assets/tracks/track1_bg_2.png",
                "./assets/tracks/track1_bg_3.png",
                "./assets/tracks/track1_bg_4.png"
    };

    auto bg_factory_bot = BackgroundFactory(paths, 15, 512);
    bg_factory_bot.get_static(*scene, 8, 8, -2);

    return RaceLevel{cars, targets, scene};
}
