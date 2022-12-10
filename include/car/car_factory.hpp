#ifndef GAME_CAR_FACTORY_HPP
#define GAME_CAR_FACTORY_HPP

#include "car.hpp"
#include "string"
#include "managers/event_manager.hpp"

class CarFactory {
public:
    static std::shared_ptr<Car> aiCar(const std::string &name, const std::string &tag, const std::string &sprite_path);

    static std::shared_ptr<Car>
    playerCar(const std::string &name, const std::string &tag, const std::string &sprite_path, const std::shared_ptr<Scene>& scene);

    static std::shared_ptr<Car>
    clientCar(const std::string &name, const std::string &tag, const std::string &sprite_path);

protected:
    static std::shared_ptr<Car>
    baseCar(const std::string &name, const std::string &tag, const std::string &sprite_path);
};

#endif //GAME_CAR_FACTORY_HPP
