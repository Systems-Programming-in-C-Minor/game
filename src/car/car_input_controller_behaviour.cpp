#include "car/car_input_controller_behaviour.hpp"

CarInputControllerBehaviour::CarInputControllerBehaviour(EventManager &event_manager, const int joystick_id)
        : JoystickListener(event_manager), _joystick_id(joystick_id) {}

void CarInputControllerBehaviour::on_axis_current(const JoystickAxisCurrentEvent &event) {
    if (event.joystick_id != _joystick_id)
        return;
    switch (event.axis) {
        case LeftJoystickX:
        case LeftTouchpadX: {
            if (std::abs(event.value) > 0.1f) {
                turn(-event.value);
            }
            break;
        }
        case LeftTrigger: {
            if (event.value > -0.9) {
                drive_backwards((event.value + 1.0f) / 2);
            }
            break;
        }
        case RightTrigger: {
            if (event.value > -0.9) {
                drive_forwards((event.value + 1.0f) / 2);
            }
            break;
        }
        default:
            break;
    }
}

void CarInputControllerBehaviour::on_button_hold(const JoystickButtonHoldEvent &event) {
    if (event.joystick_id != _joystick_id)
        return;
    if (event.button == LeftButton) {
        brake();
    }
}
