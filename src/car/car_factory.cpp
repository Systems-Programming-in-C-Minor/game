#include "car/car_factory.hpp"
#include "car/player_car_behaviour.hpp"
#include <memory>
#include <scene.hpp>

std::shared_ptr<Car>
CarFactory::base_car(const std::string &name, Car::CarColor color, const std::shared_ptr<Scene> &scene) {
    return std::make_shared<Car>(name, color, scene);
}

std::shared_ptr<Car> CarFactory::add_ai_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene) {
    return car;
}

std::shared_ptr<Car> CarFactory::add_input_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene,
                                                     CarKeybinds keybinds) {
    auto behaviour = std::make_shared<CarInputBehaviour>(scene->get_event_manager(), keybinds);
    car->add_component(behaviour);

    return car;
}

std::shared_ptr<Car> CarFactory::add_client_behaviour(std::shared_ptr<Car> car, const std::shared_ptr<Scene> &scene) {
    return car;
}
