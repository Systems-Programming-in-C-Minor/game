
#ifndef GAME_CAR_CONTROLLER_INPUT_BEHAVIOUR_HPP
#define GAME_CAR_CONTROLLER_INPUT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/joystick_listener.hpp>
#include <race/behaviours/car_behaviour.hpp>
#include "interfaces/itickable.hpp"

class CarInputControllerBehaviour : public CarBehaviour, public JoystickListener {
public:
    explicit CarInputControllerBehaviour(EventManager &event_manager, const int joystick_id);

    void on_axis_current(const JoystickAxisCurrentEvent &event) override;

    void on_button_hold(const JoystickButtonHoldEvent &event) override;

private:
    const int _joystick_id;
};

#endif //GAME_CAR_CONTROLLER_INPUT_BEHAVIOUR_HPP
