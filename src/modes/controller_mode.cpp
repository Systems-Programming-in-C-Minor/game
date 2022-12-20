#include "modes/controller_mode.hpp"
#include "race/behaviours/drive_input_controller_behaviour.hpp"
#include "race/behaviours/ai_target_behaviour.hpp"
#include <global.hpp>
#include <camera.hpp>

std::shared_ptr<Scene> ControllerMode::get(const RaceLevel &level) {

    const auto controllers = Global::get_instance()->get_engine().get_number_of_controllers();

    for (auto index = 0; index < controllers && index < level.cars.size(); index++) {
        const auto behaviour = std::make_shared<DriveInputControllerBehaviour>(level.scene->get_event_manager(), index);
        level.cars[index]->add_component(behaviour);
    }

    for (auto index = controllers; index < level.cars.size(); index++) {
        auto ai_listener_component = std::make_shared<AITargetBehaviour>(level.scene->get_event_manager(),
                                                                         level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
