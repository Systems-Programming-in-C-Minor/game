#include "car/car_input_behaviour.hpp"
#include "car/car.hpp"

CarInputBehaviour::CarInputBehaviour(EventManager &event_manager, const CarKeybinds keybinds) : KeyListener(
        event_manager), _keybinds(keybinds) {}

void CarInputBehaviour::on_key_pressed(const KeyPressedEvent &event) {}

void CarInputBehaviour::on_key_hold(const KeyHoldEvent &event) {
    const auto car = reinterpret_cast<Car *>(game_object);
    if (event.key == _keybinds.forward) {
        car->drive_forwards();
        return;
    }
    if (event.key == _keybinds.backwards) {
        car->drive_backwards();
        return;
    }
    if (event.key == _keybinds.left) {
        car->turn_left();
        return;
    }
    if (event.key == _keybinds.right) {
        car->turn_right();
        return;
    }
    if (event.key == _keybinds.brake) {
        car->brake();
        return;
    }
}

void CarInputBehaviour::on_key_released(const KeyReleasedEvent &event) {}

CarKeybinds::CarKeybinds(const Key forward, const Key backwards, const Key left, const Key right, const Key brake)
        : forward(forward), backwards(backwards), left(left), right(right), brake(brake) {
}
