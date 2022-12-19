
#ifndef GAME_GAME_BEHAVIOUR_HPP
#define GAME_GAME_BEHAVIOUR_HPP

#include <listeners/key_listener.hpp>
#include <gameobject.hpp>
#include "listeners/checkpoint_listener.hpp"

class GameBehaviour : public GameObject, public KeyListener, public CheckpointListener {
public:
    explicit GameBehaviour(EventManager &event_manager);

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

    void on_checkpoint_lapped(const CheckpointLappedEvent &event) override;

private:
    bool alt_pressed = false;
};

#endif //GAME_GAME_BEHAVIOUR_HPP
