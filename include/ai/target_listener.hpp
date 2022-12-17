
#ifndef GAME_TARGET_LISTENER_HPP
#define GAME_TARGET_LISTENER_HPP

#include <components/component.hpp>
#include <listeners/ai_listener.hpp>
#include <gameobject.hpp>

class TargetListenerComponent : public Component, public AIListener {
public:
    explicit TargetListenerComponent(EventManager &event_manager, std::vector<Vector2d> targets);

    std::shared_ptr<GameObject> get_target();

    void on_target_reached(const AITargetReachedEvent &event) override;

private:
    int _target_index = 0;

    std::vector<std::shared_ptr<GameObject>> _targets;
};
#endif //GAME_TARGET_LISTENER_HPP
