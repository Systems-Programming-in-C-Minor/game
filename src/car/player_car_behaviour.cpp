#include "car/player_car_behaviour.hpp"
#include <gameobject.hpp>

PlayerCarBehaviour::PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

void PlayerCarBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case EQUAL:
            game_object->transform.set_scale(game_object->transform.get_scale() + 0.01f);
            break;
        case MIN:
            game_object->transform.set_scale(game_object->transform.get_scale() - 0.01f);
            break;
    }
}

void PlayerCarBehaviour::on_key_hold(const KeyHoldEvent &event) {
    switch (event.key) {
        case W: {
            drive_forwards();
            break;
        }
        case S: {
            drive_backwards();
            break;
        }
        case A: {
            turn_left();
            break;
        }
        case D: {
            turn_right();
            break;
        }
        case SPACE: {
            brake();
            break;
        }
        case UP: {
            Vector2d pos_up{game_object->transform.get_position().x,
                            game_object->transform.get_position().y + 0.01f};
            game_object->transform.set_position(pos_up);
            break;
        }
        case DOWN: {
            Vector2d pos_down{game_object->transform.get_position().x,
                              game_object->transform.get_position().y - 0.01f};
            game_object->transform.set_position(pos_down);
            break;
        }
        case LEFT: {
            Vector2d pos_left{game_object->transform.get_position().x - 0.01f,
                              game_object->transform.get_position().y};
            game_object->transform.set_position(pos_left);
            break;
        }
        case RIGHT: {
            Vector2d pos_right{game_object->transform.get_position().x + 0.01f,
                               game_object->transform.get_position().y};
            game_object->transform.set_position(pos_right);
            break;
        }
    }
}

void PlayerCarBehaviour::on_key_released(const KeyReleasedEvent &event) {}
