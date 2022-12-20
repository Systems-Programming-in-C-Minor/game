#include "behaviours/game_behaviour.hpp"
#include <global.hpp>
#include "race/behaviours/checkpoint_behaviour.hpp"
#include <iostream>
#include <utility>

GameBehaviour::GameBehaviour(EventManager &event_manager, std::vector<std::shared_ptr<Car>> cars, int number_of_laps,
                             int number_to_finish) :
        GameObject("game-behaviour", "behaviour"), KeyListener(event_manager), CheckpointListener(event_manager),
        _number_of_laps(number_of_laps),
        _number_to_finish(number_to_finish) {
    for (int index = 0; index < cars.size(); index++)
        _cars.emplace(cars[index], index + 1);
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
                for (const auto &car: _cars)
                    car.first->is_enabled = true;
                _started = true;
            }
            break;
        }
        default:
            break;
    }
}

void GameBehaviour::on_checkpoint_lapped(const CheckpointLappedEvent &event) {
    if (event.checkpoint_behaviour->get_number_of_laps() <= _number_of_laps)
        return;

    const auto car_behaviour = reinterpret_cast<Car *>(event.checkpoint_behaviour->game_object);
    car_behaviour->is_enabled = false;

    int finished = 0;
    for (auto &car: _cars) {
        if (car.first->get_component<CheckpointBehaviour>()->get_number_of_laps() >= _number_of_laps)
            finished++;
    }

    if (finished > _number_to_finish || finished >= _cars.size()) {
        // TODO implement finish with text

        // Sort cars
        std::multimap<int, std::shared_ptr<Car>> car_multimap;
        for (auto &it: _cars) {
            car_multimap.insert({it.second, it.first});
        }

        for (auto &it: car_multimap) {
            std::cout << it.first << ' ' << it.second->get_name() << std::endl;
        }
    }
}

void GameBehaviour::on_checkpoint_touched(const CheckpointTouchedEvent &event) {

}
