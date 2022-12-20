#include "listeners/mode_listener.hpp"
#include "uiobject.hpp"
#include "global.hpp"
#include "levels/level1_factory.hpp"
#include "modes/singleplayer_mode.hpp"
#include "modes/coop_mode.hpp"
#include "modes/controller_mode.hpp"

ModeListener::ModeListener(EventManager &event_manager) : GameObject("mode-listener", "mode-listener"),
                                                          UiObjectListener(event_manager) {}

void ModeListener::on_uiobject_released(const UiObjectReleasedEvent &event) {
    if (event.button != BUTTON_LEFT)
        return;

    const auto name = event.ui_object.get_name();
    const auto level = Level1Factory::get();

    if (name == "singleplayer") {
        Global::get_instance()->get_engine().load_scene(SingleplayerMode::get(level));
        return;
    }
    if (name == "coop") {
        Global::get_instance()->get_engine().load_scene(CoopMode::get(level));
        return;
    }
    if (name == "controller") {
        Global::get_instance()->get_engine().load_scene(ControllerMode::get(level));
        return;
    }
    if (name == "multiplayer") {
        // TODO implement multiplayer mode
        return;
    }
}
