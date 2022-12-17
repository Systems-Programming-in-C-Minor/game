#include "modes/controller_mode.hpp"
#include "car/car_input_behaviour.hpp"
#include "ai/target_listener.hpp"
#include "car/car_input_controller_behaviour.hpp"
#include <global.hpp>

std::shared_ptr<Scene> ControllerMode::get(const Level& level) {

    const auto controllers = Global::get_instance()->get_engine().get_number_of_controllers();

    for (auto index = 0; index < controllers; index++) {
        const auto behaviour = std::make_shared<CarInputControllerBehaviour>(level.scene->get_event_manager(), index);
        level.cars[index]->add_component(behaviour);
    }

    for (int index = controllers; index < level.cars.size(); index++) {
        auto ai_listener_component =
                std::make_shared<TargetListenerComponent>(level.scene->get_event_manager(), level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
