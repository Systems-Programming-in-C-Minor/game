#include "car/car_input_behaviour.hpp"
#include <gameobject.hpp>

CarInputBehaviour::CarInputBehaviour(EventManager &event_manager, const CarKeybinds keybinds) : KeyListener(
        event_manager), _keybinds(keybinds) {}

void CarInputBehaviour::on_key_pressed(const KeyPressedEvent &event) {}

void CarInputBehaviour::on_key_hold(const KeyHoldEvent &event) {
    if (event.key == _keybinds.forward) {
        drive_forwards();
        return;
    }
    if (event.key == _keybinds.backwards) {
        drive_backwards();
        return;
    }
    if (event.key == _keybinds.left) {
        turn_left();
        return;
    }
    if (event.key == _keybinds.right) {
        turn_right();
        return;
    }
    if (event.key == _keybinds.brake) {
        brake();
        return;
    }
}

void CarInputBehaviour::on_key_released(const KeyReleasedEvent &event) {}

CarKeybinds::CarKeybinds(const Key forward, const Key backwards, const Key left, const Key right,
                         const Key brake) : forward(forward), backwards(backwards), left(left),
                                                              right(right), brake(brake) {

}
