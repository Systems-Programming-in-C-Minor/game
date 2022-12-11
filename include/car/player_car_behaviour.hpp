
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
    const float max_speed_forward = 1.f;
    const float max_speed_backwards = -1.f;
    const float max_drive_force = 1.f;
    const float current_traction = 1.f;
    const float steer_torque = 5.f;
    const float steer_torque_offset = 2.f;
    const float max_lateral_impulse = 1.f;
    const float drift_friction = 1.f;
    const float angular_friction = 1.f;
    const float drag_modifier = 1.f;

    DriveState drive_state = NeutralDrive;
    SteerState steer_state = NeutralSteer;

    void friction();

    void drive();

    void turn();

public:
    explicit PlayerCarBehaviour(EventManager &event_manager);

    void tick(GameObject &object) override;

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_hold(const KeyHoldEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

};

#endif //GAME_PLAYER_CAR_BEHAVIOUR_HPP
