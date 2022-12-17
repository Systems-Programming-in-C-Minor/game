#include "modes/coop_mode.hpp"
#include "car/car_input_behaviour.hpp"

std::shared_ptr<Scene> CoopMode::get(Level level) {
    const auto behaviour = std::make_shared<CarInputBehaviour>(level.scene->get_event_manager());
    level.cars[0]->add_component(behaviour);

    const auto co_op = std::make_shared<CarInputBehaviour>(
            level.scene->get_event_manager(), CarKeybinds{I, K, J, L, U});
    level.cars[1]->add_component(co_op);

    return level.scene;
}
