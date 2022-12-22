#include "modes/singleplayer_mode.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/ai_target_behaviour.hpp"
#include "overlay/speed_indicator.hpp"
#include <camera.hpp>
#include "listeners/car_audio_listener.hpp"
#include "behaviours/high_score_behaviour.hpp"

std::shared_ptr<Scene> SingleplayerMode::get(const RaceLevel &level) {
    level.scene->get_camera()->mtp = 22.f;

    const auto behaviour = std::make_shared<DriveInputBehaviour>(level.scene->get_event_manager());
    const auto car_audio_listener = std::make_shared<CarAudioListenerComponent>(level.scene->get_event_manager());
    const auto speed_indicator = SpeedIndicator::get(level.scene->get_event_manager());
    const auto high_score_behaviour = std::make_shared<HighScoreBehaviour>(level.scene->get_event_manager());

    level.scene->gameobjects.push_back(speed_indicator);

    level.cars[0]->add_component(behaviour);
    level.cars[0]->add_component(speed_indicator->get_component<SpeedIndicator>());
    level.cars[0]->add_child(level.scene->get_camera());
    level.scene->get_camera()->mtp = 10.f;
    level.cars[0]->add_component(car_audio_listener);
    level.cars[0]->add_component(high_score_behaviour);

    for (const auto& sound : car_audio_listener->get_sounds()) {
        level.cars[0]->add_component(sound);
    }

    for (int index = 1; index < level.cars.size(); index++) {
        auto ai_listener_component = std::make_shared<AITargetBehaviour>(level.scene->get_event_manager(),
                                                                         level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
