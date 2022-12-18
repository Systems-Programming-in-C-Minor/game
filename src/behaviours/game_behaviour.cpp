#include "behaviours/game_behaviour.hpp"
#include <global.hpp>

GameBehaviour::GameBehaviour(EventManager &event_manager) : GameObject("game-behaviour", "behaviour"), KeyListener(event_manager) {}

void GameBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case ALT_LEFT: {
            _ALT = true;
            break;
        }
        case ENTER: {
            if (_ALT)
                Global::get_instance()->get_engine().get_renderer()->toggle_fullscreen();
            break;
        }
        case D: {
            if (_ALT)
                Global::get_instance()->get_engine().get_renderer()->toggle_debug_mode();
            break;
        }
        default:
            break;
    }
}

void GameBehaviour::on_key_released(const KeyReleasedEvent &event) {
    switch (event.key) {
        case ALT_LEFT: {
            _ALT = false;
            break;
        }
        default:
            break;
    }
}
