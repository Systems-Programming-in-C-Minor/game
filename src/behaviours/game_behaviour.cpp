#include "behaviours/game_behaviour.hpp"
#include <global.hpp>
#include "race/behaviours/checkpoint_behaviour.hpp"
#include <iostream>

GameBehaviour::GameBehaviour(EventManager &event_manager) :
        GameObject("game-behaviour", "behaviour"), KeyListener(event_manager), CheckpointListener(event_manager) {}

void GameBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case ALT_LEFT: {
            alt_pressed = true;
            break;
        }
        case ENTER: {
            if (alt_pressed)
                Global::get_instance()->get_engine().get_renderer()->toggle_fullscreen();
            break;
        }
        case D: {
            if (alt_pressed)
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
            alt_pressed = false;
            break;
        }
        default:
            break;
    }
}

void GameBehaviour::on_checkpoint_lapped(const CheckpointLappedEvent &event) {
    std::cout << "lap " << event.checkpoint_behaviour->game_object->get_name() << std::endl;
}
