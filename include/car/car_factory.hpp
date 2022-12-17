#ifndef GAME_CAR_FACTORY_HPP
#define GAME_CAR_FACTORY_HPP

#include "car.hpp"
#include "string"
#include "managers/event_manager.hpp"
#include "player_car_behaviour.hpp"

class CarFactory {
public:
    static std::shared_ptr<Car>
    base_car(const std::string &name, Car::CarColor color, const std::shared_ptr<Scene> &scene);

    static std::shared_ptr<Car> add_ai_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene);

    static std::shared_ptr<Car> add_input_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene,
                                                    CarKeybinds keybinds = CarKeybinds());

    static std::shared_ptr<Car> add_client_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_CAR_FACTORY_HPP
