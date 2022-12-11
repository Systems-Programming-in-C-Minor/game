
#ifndef GAME_PLAYER_CAR_BEHAVIOUR_HPP
#define GAME_PLAYER_CAR_BEHAVIOUR_HPP

#include <components/component.hpp>
#include <listeners/key_listener.hpp>
#include "interfaces/itickable.hpp"

enum DriveState {
    NeutralDrive,
    Forward,
    Backward,
};


enum SteerState {
    NeutralSteer,
    Right,
    Left
};

class PlayerCarBehaviour : public Component, public KeyListener, public ITickable {

private:
    const float max_speed_forward = 4.f;
    const float max_speed_backwards = -2.f;
    const float max_drive_force = 3.8f;
    const float current_traction = 1.f;
    const float max_lateral_impulse = 1.f;
    const float drift_friction = 1.f;
    const float angular_friction = 1.f;
    const float drag_modifier = 8.f;

    void friction();

    void drive(float desired_speed);

public:
    explicit PlayerCarBehaviour(EventManager &event_manager);

    void tick(GameObject &object) override;

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_hold(const KeyHoldEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

};

#endif //GAME_PLAYER_CAR_BEHAVIOUR_HPP
