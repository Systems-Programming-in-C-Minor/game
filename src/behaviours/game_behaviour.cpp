#include "behaviours/game_behaviour.hpp"
#include <global.hpp>
#include "race/behaviours/checkpoint_behaviour.hpp"
#include <iostream>
#include "race/objects/checkpoint.hpp"

GameBehaviour::GameBehaviour(EventManager &event_manager,
                             std::vector<std::shared_ptr<Car>> cars,
                             int number_of_laps,
                             int cars_to_finish) :
        GameObject("game-behaviour", "behaviour"),
        KeyListener(event_manager),
        JoystickListener(event_manager),
        CheckpointListener(event_manager),
        MultiplayerListener(event_manager),
        _number_of_laps(number_of_laps),
        _cars_to_finish(cars_to_finish) {
    for (auto &car: cars)
        _cars.emplace(car, 0);
}

void GameBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    const auto alt_pressed = Global::get_instance()->input.get_key(ALT_LEFT);

    switch (event.key) {
        case ENTER:
            if (alt_pressed) toggle_fullscreen();
            break;
        case D:
            if (alt_pressed) toggle_debug();
            break;
        case RIGHT:
            if (alt_pressed) speedup_game();
            break;
        case LEFT:
            if (alt_pressed) slowdown_game();
            break;
        default:
            break;
    }
}

void GameBehaviour::on_key_released(const KeyReleasedEvent &event) {
    switch (event.key) {
        case SPACE:
            start();
            break;
        default:
            break;
    }
}

void GameBehaviour::on_checkpoint_lapped(const CheckpointLappedEvent &event) {
    if (event.checkpoint_behaviour->get_number_of_laps() < _number_of_laps)
        return;

    const auto car_behaviour = reinterpret_cast<Car *>(event.checkpoint_behaviour->game_object);
    car_behaviour->is_enabled = false;

    int finished = 0;
    for (auto &car: _cars) {
        if (car.first->get_component<CheckpointBehaviour>()->get_number_of_laps() >= _number_of_laps) {
            finished++;
            car.second++;
        }
    }

    if (finished > _cars_to_finish || finished >= _cars.size())
    {
        finish();
    }
}

void GameBehaviour::on_checkpoint_reached(const CheckpointReachedEvent &event) {
    const auto car_object = reinterpret_cast<Car *>(event.checkpoint_behaviour->game_object);

    for (auto &car: _cars) {
        if (car.first->get_name() == car_object->get_name()) {
            car.second++;
            break;
        }
    }
}

void GameBehaviour::_start() {
    for (const auto &car: _cars)
        car.first->is_enabled = true;
    _started = true;
}

void GameBehaviour::finish() {
    if (_finished)
        return;

    // TODO implement finish with text
    _finished = true;

    // Sort cars
    std::multimap<int, std::shared_ptr<Car>> car_multimap;
    for (auto &it: _cars) {
        it.first->is_enabled = false;
        car_multimap.insert({it.second * -1, it.first});
    }

    int position = 0;
    for (auto &it: car_multimap) {
        position++;
        std::cout << position << ' ' << it.second->get_name() << std::endl;
    }
}

void GameBehaviour::on_start_game(const StartGameMultiplayerEvent &event) {
    _start();
}

void GameBehaviour::on_stop_game(const StopGameMultiplayerEvent &event) {
    finish();
}

void GameBehaviour::toggle_fullscreen() {
    Global::get_instance()->get_engine().get_renderer()->toggle_fullscreen();
}

void GameBehaviour::toggle_debug() {
    Global::get_instance()->get_engine().get_renderer()->toggle_debug_mode();
}

void GameBehaviour::start() {
    if (!_started) {
        const auto multiplayer_manager = Global::get_instance()->get_engine().multiplayer_manager;
        if (multiplayer_manager != nullptr) {
            if (multiplayer_manager->is_host) {
                multiplayer_manager->start_game();
            }
        } else {
            _start();
        }
    }
}

void GameBehaviour::speedup_game() {
    const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
    (ticks < 1000) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks + 10) : void();
}

void GameBehaviour::slowdown_game() {
    const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
    (ticks > 10) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks - 10) : void();
}

void GameBehaviour::on_button_pressed(const JoystickButtonPressedEvent &event) {
    switch (event.button) {
        case AButton:
            start();
            break;
        case XButton:
            toggle_debug();
            break;
        case YButton:
            toggle_fullscreen();
            break;
        default:
            break;
    }
}
