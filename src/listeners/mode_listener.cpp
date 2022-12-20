#include "listeners/mode_listener.hpp"
#include "uiobject.hpp"
#include <iostream>

ModeListener::ModeListener(EventManager &event_manager) : GameObject("mode-listener", "mode-listener"), UiObjectListener(event_manager) {}

void ModeListener::on_uiobject_released(const UiObjectReleasedEvent &event) {
    if (event.button != BUTTON_LEFT)
        return;

    const auto name = event.ui_object.get_name();

    if (name == "singleplayer") {
        std::cout << name << std::endl;
        return;
    }
    if (name == "coop") {
        std::cout << name << std::endl;
        return;
    }
    if (name == "controller") {
        std::cout << name << std::endl;
        return;
    }
    if (name == "multiplayer") {
        std::cout << name << std::endl;
        return;
    }
}
