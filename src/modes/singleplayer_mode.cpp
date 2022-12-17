#include "modes/singleplayer_mode.hpp"
#include "car/car_input_behaviour.hpp"

std::shared_ptr<Scene> SingleplayerMode::get(Level level) {
    const auto behaviour = std::make_shared<CarInputBehaviour>(level.scene->get_event_manager());
    level.cars[0]->add_component(behaviour);

    return level.scene;
}
