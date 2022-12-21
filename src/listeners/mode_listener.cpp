#include "listeners/mode_listener.hpp"
#include "uiobject.hpp"
#include "global.hpp"
#include "levels/level1_factory.hpp"
#include "levels/level2_factory.hpp"
#include "modes/singleplayer_mode.hpp"
#include "modes/coop_mode.hpp"
#include "modes/controller_mode.hpp"
#include "modes/multiplayer_mode.hpp"
#include "scenes/level_selector_factory.hpp"

ModeListener::ModeListener(EventManager &event_manager) : GameObject("mode-listener", "mode-listener"),
                                                          UiObjectListener(event_manager) {}

void ModeListener::on_uiobject_released(const UiObjectReleasedEvent &event) {
    if (event.button != BUTTON_LEFT)
        return;

    const auto name = event.ui_object.get_name();

    if (name == "singleplayer") {
        Global::get_instance()->get_engine().load_scene(LevelSelectorFactory::get(Singleplayer));
        return;
    }
    if (name == "coop") {
        Global::get_instance()->get_engine().load_scene(LevelSelectorFactory::get(Coop));
        return;
    }
    if (name == "controller") {
        Global::get_instance()->get_engine().load_scene(LevelSelectorFactory::get(Controller));
        return;
    }
    if (name == "multiplayer") {
        Global::get_instance()->get_engine().load_scene(LevelSelectorFactory::get(Multiplayer));
        return;
    }
}
