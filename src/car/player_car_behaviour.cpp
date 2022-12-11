#include "car/player_car_behaviour.hpp"
#include "../../cmake-build-debug/_deps/fmt-src/include/fmt/core.h"
#include <gameobject.hpp>
#include <cmath>

PlayerCarBehaviour::PlayerCarBehaviour(EventManager &event_manager) : KeyListener(event_manager) {}

void PlayerCarBehaviour::tick(GameObject &object) {

}

void PlayerCarBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case EQUAL:
            game_object->transform.set_scale(game_object->transform.get_scale() + 0.01f);
            break;
        case MIN:
            game_object->transform.set_scale(game_object->transform.get_scale() - 0.01f);
            break;
        case Z:
            game_object->transform.set_angle(game_object->transform.get_angle() + 0.1f);
            break;
        case X:
            game_object->transform.set_angle(game_object->transform.get_angle() - 0.1f);
            break;
    }
}

void PlayerCarBehaviour::on_key_hold(const KeyHoldEvent &event) {
    auto center = game_object->transform.get_position();
    auto angle = game_object->transform.get_angle();
    auto angle_force = Vector2d{(float) sin(angle), (float) cos(angle)};

    switch (event.key) {
        case W: {
            game_object->get_component<RigidBody>()->apply_force(angle_force, center);
            break;
        }
        case S: {
            angle_force = Vector2d{angle_force.x * -1.f, angle_force.y * -1.f};
            game_object->get_component<RigidBody>()->apply_force(angle_force, center);
            break;
        }
        case A: {
            game_object->get_component<RigidBody>()->apply_torque(1.2f);
//            game_object->get_component<RigidBody>()->apply_force(angle_changed);
            break;
        }
        case D: {
            game_object->get_component<RigidBody>()->apply_torque(-1.2f);
//            game_object->get_component<RigidBody>()->set_linear_velocity(angle_changed);
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
