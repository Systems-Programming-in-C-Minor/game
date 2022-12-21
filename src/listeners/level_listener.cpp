#include "listeners/level_listener.hpp"
#include "uiobject.hpp"
#include "global.hpp"
#include "levels/level1_factory.hpp"
#include "levels/level2_factory.hpp"
#include "modes/singleplayer_mode.hpp"
#include "modes/coop_mode.hpp"
#include "modes/controller_mode.hpp"
#include "modes/multiplayer_mode.hpp"

LevelListener::LevelListener(EventManager &event_manager, Mode mode) : GameObject("mode-listener", "mode-listener"),
                                                                       UiObjectListener(event_manager), mode(mode) {}

void LevelListener::on_uiobject_released(const UiObjectReleasedEvent &event) {
    if (event.button != BUTTON_LEFT)
        return;

    const auto name = event.ui_object.get_name();

    RaceLevel level = name == "level-2" ? Level2Factory::get() : Level1Factory::get();

    if (mode == Singleplayer) {
        Global::get_instance()->get_engine().load_scene(SingleplayerMode::get(level));
        return;
    }
    if (mode == Coop) {
        Global::get_instance()->get_engine().load_scene(CoopMode::get(level));
        return;
    }
    if (mode == Controller) {
        Global::get_instance()->get_engine().load_scene(ControllerMode::get(level));
        return;
    }
    if (mode == Multiplayer) {
        Global::get_instance()->get_engine().load_scene(MultiplayerMode::get(level));
        return;
    }
}
