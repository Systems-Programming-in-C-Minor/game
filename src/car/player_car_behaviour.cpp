#include "car/player_car_behaviour.hpp"
#include "../../cmake-build-debug/_deps/fmt-src/include/fmt/core.h"
#include <gameobject.hpp>
#include <cmath>

PlayerCarBehaviour::PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

void PlayerCarBehaviour::tick(GameObject &object) {
    friction();
    drive();
    turn();
}

void PlayerCarBehaviour::friction() {
    auto &body = *game_object->get_component<RigidBody>();


    //calculate the counter lateral impulse based on drift parameters
    Vector2d impulse = Vector2d{body.get_mass() * -body.get_lateral_velocity().x,
                                body.get_mass() * -body.get_lateral_velocity().y};
    if (impulse.length() > max_lateral_impulse)
        impulse = Vector2d{impulse.x * max_lateral_impulse / impulse.length(),
                           impulse.y * max_lateral_impulse / impulse.length()};

    // apply the impulse
    body.apply_linear_impulse(Vector2d{impulse.x * drift_friction, impulse.y * drift_friction},
                              body.get_world_center());

    //angular velocity
    body.apply_angular_impulse(angular_friction * body.get_inertia() * -body.get_angular_velocity());

    //forward linear velocity
    Vector2d currentForwardNormal = body.get_forward_velocity();
    float currentForwardSpeed = currentForwardNormal.normalize();
    float dragForceMagnitude = -2 * currentForwardSpeed * drag_modifier;

    body.apply_force(Vector2d{currentForwardNormal.x * current_traction * dragForceMagnitude,
                              currentForwardNormal.y * current_traction * dragForceMagnitude}, body.get_world_center());
}

void PlayerCarBehaviour::drive() {
    auto &body = *game_object->get_component<RigidBody>();

    //find current speed in forward direction
    float current_speed = body.get_current_speed();

    float desired_speed = 0.f;
    if (drive_state == Forward)
        desired_speed = max_speed_forward;
    if (drive_state == Backward)
        desired_speed = max_speed_backwards;

    //apply necessary force
    float force = (desired_speed > current_speed) ? max_drive_force : -max_drive_force;
    if (desired_speed != current_speed) {
        auto force_vec = Vector2d{body.get_world_vector(Vector2d{0, 1}).x * current_traction * force,
                                  body.get_world_vector(Vector2d{0, 1}).y * current_traction * force};
        body.apply_force(force_vec, body.get_world_center());
    }
}

void PlayerCarBehaviour::turn() {
    float desiredTorque = 0;
    // set our torque
    float torque = steer_torque + steer_torque_offset;
    if (steer_state == Left)
        desiredTorque = torque;
    if (steer_state == Right)
        desiredTorque = -torque;

    // reverse the torque if we are going backwards
    if (drive_state == Backward)
        desiredTorque = -desiredTorque;

    game_object->get_component<RigidBody>()->apply_torque(desiredTorque);
}

void PlayerCarBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case W: {
            drive_state = Forward;
            break;
        }
        case S: {
            drive_state = Backward;
            break;
        }
        case A: {
            steer_state = Left;
            break;
        }
        case D: {
            steer_state = Right;
            break;
        }
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
        case Z:
            game_object->transform.set_angle(game_object->transform.get_angle() + 0.01f);
            break;
        case X:
            game_object->transform.set_angle(game_object->transform.get_angle() - 0.01f);
            break;
    }
}

void PlayerCarBehaviour::on_key_released(const KeyReleasedEvent &event) {
    switch (event.key) {
        case W: {
            if (drive_state == Forward)
                drive_state = NeutralDrive;
            break;
        }
        case S: {
            if (drive_state == Backward)
                drive_state = NeutralDrive;
            break;
        }
        case A: {
            if (steer_state == Left)
                steer_state = NeutralSteer;
            break;
        }
        case D: {
            if (steer_state == Right)
                steer_state = NeutralSteer;
            break;
        }
    }
}
