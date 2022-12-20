#include "modes/singleplayer_mode.hpp"
#include "race/objects/car.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"
#include "race/behaviours/ai_target_behaviour.hpp"
#include <camera.hpp>

#include "listeners/car_audio_listener.hpp"

std::shared_ptr<Scene> SingleplayerMode::get(const RaceLevel &level) {
    const auto behaviour = std::make_shared<DriveInputBehaviour>(level.scene->get_event_manager());
    level.cars[0]->add_component(behaviour);
    level.cars[0]->add_child(level.scene->get_camera());
    level.cars[0]->add_component(std::make_shared<CarAudioListenerComponent>(level.scene->get_event_manager()));

    for (int index = 1; index < level.cars.size(); index++) {
        auto ai_listener_component = std::make_shared<AITargetBehaviour>(level.scene->get_event_manager(),
                                                                         level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
