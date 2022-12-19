
#ifndef GAME_CAR_INPUT_BEHAVIOUR_HPP
#define GAME_CAR_INPUT_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/key_listener.hpp>
#include "interfaces/itickable.hpp"

class Car;

class CarKeybinds {
public:
    explicit CarKeybinds(Key forward = W, Key backwards = S, Key left = A, Key right = D, Key brake = SPACE);

    const Key forward;
    const Key backwards;
    const Key left;
    const Key right;
    const Key brake;
};

class CarInputBehaviour : public Component, public KeyListener {
public:
    explicit CarInputBehaviour(EventManager &event_manager, CarKeybinds keybinds = CarKeybinds());

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_hold(const KeyHoldEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

private:
    const CarKeybinds _keybinds;
};

#endif //GAME_CAR_INPUT_BEHAVIOUR_HPP
