#include "behaviours/game_behaviour.hpp"
#include <global.hpp>
#include "race/behaviours/checkpoint_behaviour.hpp"
#include <iostream>
#include <utility>
#include "race/objects/checkpoint.hpp"

GameBehaviour::GameBehaviour(EventManager &event_manager, std::vector<std::shared_ptr<Car>> cars, int number_of_laps,
                             int cars_to_finish) :
        GameObject("game-behaviour", "behaviour"), KeyListener(event_manager), CheckpointListener(event_manager),
        MultiplayerListener(event_manager),
        _number_of_laps(number_of_laps),
        _cars_to_finish(cars_to_finish) {
    for (auto &car: cars)
        _cars.emplace(car, 0);
}

void GameBehaviour::on_key_pressed(const KeyPressedEvent &event) {
    switch (event.key) {
        case ALT_LEFT: {
            _alt_pressed = true;
            break;
        }
        case ENTER: {
            if (_alt_pressed)
                Global::get_instance()->get_engine().get_renderer()->toggle_fullscreen();
            break;
        }
        case D: {
            if (_alt_pressed)
                Global::get_instance()->get_engine().get_renderer()->toggle_debug_mode();
            break;
        }
        case RIGHT: {
            if (_alt_pressed) {
                const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
                (ticks < 1000) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks + 10) : void();
            }
            break;
        }
        case LEFT: {
            if (_alt_pressed) {
                const int ticks = Global::get_instance()->get_engine().get_ticks_per_second();
                (ticks > 10) ? Global::get_instance()->get_engine().set_ticks_per_second(ticks - 10) : void();
            }
        }
        default:
            break;
    }
}

void GameBehaviour::on_key_released(const KeyReleasedEvent &event) {
    switch (event.key) {
        case ALT_LEFT: {
            _alt_pressed = false;
            break;
        }
        case SPACE: {
            if (!_started) {
                const auto multiplayer_manager = Global::get_instance()->get_engine().multiplayer_manager;
                if (multiplayer_manager != nullptr) {
                    if (multiplayer_manager->is_host) {
                        multiplayer_manager->start_game();
                    }
                } else {
                    start();
                }
            }
            break;
        }
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
        finish();
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

void GameBehaviour::start() {
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
    start();
}

void GameBehaviour::on_stop_game(const StopGameMultiplayerEvent &event) {
    finish();
}
