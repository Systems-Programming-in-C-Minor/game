#include "car/player_car_behaviour.hpp"

PlayerCarBehaviour::PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

void PlayerCarBehaviour::on_key_pressed(const KeyPressedEvent &event) {}

void PlayerCarBehaviour::on_key_hold(const KeyHoldEvent &event) {}

void PlayerCarBehaviour::on_key_released(const KeyReleasedEvent &event) {}
