
#ifndef GAME_GAME_BEHAVIOUR_HPP
#define GAME_GAME_BEHAVIOUR_HPP

#include <listeners/key_listener.hpp>
#include <gameobject.hpp>

class GameBehaviour : public GameObject, public KeyListener {

public:
    explicit GameBehaviour(EventManager &event_manager);

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

private:
    bool _ALT = false;
};

#endif //GAME_GAME_BEHAVIOUR_HPP
