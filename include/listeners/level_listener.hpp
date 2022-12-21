
#ifndef GAME_LEVEL_LISTENER_HPP
#define GAME_LEVEL_LISTENER_HPP

#include "listeners/uiobject_listener.hpp"
#include <gameobject.hpp>
#include "listeners/mode_listener.hpp"

class LevelListener : public GameObject, public UiObjectListener {
public:
    explicit LevelListener(EventManager &event_manager, Mode mode);

    void on_uiobject_released(const UiObjectReleasedEvent &event) override;

private:
    const Mode mode;
};

#endif //GAME_LEVEL_LISTENER_HPP
