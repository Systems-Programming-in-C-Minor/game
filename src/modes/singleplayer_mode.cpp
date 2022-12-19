#include "modes/singleplayer_mode.hpp"
#include "car/car.hpp"
#include "car/car_input_behaviour.hpp"
#include "ai/target_listener.hpp"

std::shared_ptr<Scene> SingleplayerMode::get(const Level& level) {
    const auto behaviour = std::make_shared<CarInputBehaviour>(level.scene->get_event_manager());
    level.cars[0]->add_component(behaviour);

    for (int index = 1; index < level.cars.size(); index++) {
        auto ai_listener_component =
                std::make_shared<TargetListenerComponent>(level.scene->get_event_manager(), level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(level.cars[index]->get_component<RigidBody>(), ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
