#include "modes/coop_mode.hpp"
#include "ai/target_listener.hpp"
#include "race/objects/car.hpp"
#include "race/behaviours/drive_input_behaviour.hpp"

std::shared_ptr<Scene> CoopMode::get(const RaceLevel& level) {
    const auto behaviour = std::make_shared<DriveInputBehaviour>(level.scene->get_event_manager());
    level.cars[0]->add_component(behaviour);

    const auto co_op = std::make_shared<DriveInputBehaviour>(
            level.scene->get_event_manager(), DriveKeybinds{I, K, J, L, U});
    level.cars[1]->add_component(co_op);

    for (int index = 2; index < level.cars.size(); index++) {
        auto ai_listener_component =
                std::make_shared<TargetListenerComponent>(level.scene->get_event_manager(), level.targets);
        level.cars[index]->add_component(ai_listener_component);
        const auto ai_behaviour = std::make_shared<AIBehaviour>(level.cars[index]->get_component<RigidBody>(), ai_listener_component->get_target());
        level.cars[index]->add_component(ai_behaviour);
    }

    return level.scene;
}
