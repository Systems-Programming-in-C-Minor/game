
#ifndef GAME_WINNING_FACTORY_HPP
#define GAME_WINNING_FACTORY_HPP

#include <scene.hpp>
#include <race/objects/car.hpp>

class WinningFactory {
public:
    static std::shared_ptr<Scene> get(std::vector<std::shared_ptr<Car>> cars);
};


#endif //GAME_WINNING_FACTORY_HPP
