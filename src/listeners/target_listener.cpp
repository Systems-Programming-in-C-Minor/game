#include "listeners/target_listener.hpp"

TargetListenerComponent::TargetListenerComponent(EventManager &event_manager, std::vector<Vector2d> targets)
        : AIListener(event_manager) {
    std::vector<std::shared_ptr<GameObject>> target_objects;
    for (const auto target: targets) {
        target_objects.push_back(std::make_shared<GameObject>("target", "target", Transform{target}));
    }
    _targets = target_objects;
};

std::shared_ptr<GameObject> TargetListenerComponent::get_target() {
    return _targets[_target_index];
}

void TargetListenerComponent::on_target_reached(const AITargetReachedEvent &event) {
    auto test = game_object->get_component<AIBehaviour>()->game_object;
    if (event.ai_behaviour.game_object != test)
        return;

    _target_index++;
    if (_targets.size() <= _target_index)
        _target_index = 0;

    event.ai_behaviour.set_target(_targets[_target_index]);
}


