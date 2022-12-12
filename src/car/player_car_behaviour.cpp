#include "car/player_car_behaviour.hpp"
#include <gameobject.hpp>

PlayerCarBehaviour::PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

void PlayerCarBehaviour::tick(GameObject &object) {
    friction();
}

void PlayerCarBehaviour::friction() {
    auto &body = *game_object->get_component<RigidBody>();

    //calculate the counter lateral impulse based on drift parameters
    Vector2d impulse = body.get_lateral_velocity() * -body.get_mass();
    if (impulse.length() > max_lateral_impulse)
        impulse = impulse * (max_lateral_impulse / impulse.length());

    // apply the impulse
    body.apply_linear_impulse(impulse * drift_friction, body.get_world_center());

    //angular velocity
    body.apply_angular_impulse(angular_friction * body.get_inertia() * -body.get_angular_velocity());

    //forward linear velocity
    Vector2d currentForwardNormal = body.get_forward_velocity();
    float currentForwardSpeed = currentForwardNormal.normalize();
    float dragForceMagnitude = -2 * currentForwardSpeed * drag_modifier;

    body.apply_force(currentForwardNormal * current_traction * dragForceMagnitude, body.get_world_center());
}

void PlayerCarBehaviour::drive(float desired_speed) {
    auto &body = *game_object->get_component<RigidBody>();

    //find current speed in forward direction
    float current_speed = body.get_current_speed();

    //apply necessary force
    float force = (desired_speed > current_speed) ? max_drive_force : -max_drive_force;
    if (desired_speed != current_speed) {
        auto force_vec = body.get_world_vector(Vector2d{0, 1}) * current_traction * force;
        body.apply_force(force_vec, body.get_world_center());
    }
}

void PlayerCarBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case EQUAL:
            game_object->transform.set_scale(game_object->transform.get_scale() + 0.01f);
            break;
        case MIN:
            game_object->transform.set_scale(game_object->transform.get_scale() - 0.01f);
            break;
    }
}

void PlayerCarBehaviour::on_key_hold(const KeyHoldEvent &event) {
    auto &body = *game_object->get_component<RigidBody>();

    switch (event.key) {
        case W: {
            drive(max_speed_forward);
            break;
        }
        case S: {
            drive(max_speed_backwards);
            break;
        }
        case A: {
            body.apply_angular_impulse(steering_impulse);
            break;
        }
        case D: {
            body.apply_angular_impulse(-steering_impulse);
            break;
        }
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
    }
}

void PlayerCarBehaviour::on_key_released(const KeyReleasedEvent &event) {}
