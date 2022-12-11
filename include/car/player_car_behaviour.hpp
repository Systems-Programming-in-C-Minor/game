
#ifndef GAME_PLAYER_CAR_BEHAVIOUR_HPP
#define GAME_PLAYER_CAR_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/key_listener.hpp>
#include "interfaces/itickable.hpp"

class PlayerCarBehaviour : public Component, public KeyListener, public ITickable {
public:
    explicit PlayerCarBehaviour(EventManager &event_manager);

    void tick(GameObject &object) override;

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_hold(const KeyHoldEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

};

#endif //GAME_PLAYER_CAR_BEHAVIOUR_HPP
