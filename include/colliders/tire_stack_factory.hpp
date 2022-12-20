#ifndef GAME_TIRE_STACK_FACTORY_HPP
#define GAME_TIRE_STACK_FACTORY_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"
#include "string"

class TireStackFactory {
public:
    static std::shared_ptr<GameObject> get(Vector2d pos, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_TIRE_STACK_FACTORY_HPP
