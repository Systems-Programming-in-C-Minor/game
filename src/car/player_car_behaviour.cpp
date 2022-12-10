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
        case Z:
            game_object->transform.set_angle(game_object->transform.get_angle() + 0.1f);
            break;
        case X:
            game_object->transform.set_angle(game_object->transform.get_angle() - 0.1f);
            break;
    }
}

void PlayerCarBehaviour::on_key_hold(const KeyHoldEvent &event) {
    switch (event.key) {
        case W:
            break;
        case S:
            break;
        case A:
            break;
        case D:
            break;
    }
}

void PlayerCarBehaviour::on_key_released(const KeyReleasedEvent &event) {}
