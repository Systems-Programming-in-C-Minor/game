
#ifndef GAME_MODE_LISTENER_HPP
#define GAME_MODE_LISTENER_HPP

#include "listeners/uiobject_listener.hpp"
#include <gameobject.hpp>

enum Mode {
    Singleplayer,
    Coop,
    Controller,
    Multiplayer
};

class ModeListener : public GameObject, public UiObjectListener {
public:
    explicit ModeListener(EventManager &event_manager);

    void on_uiobject_released(const UiObjectReleasedEvent &event) override;

};

#endif //GAME_MODE_LISTENER_HPP
