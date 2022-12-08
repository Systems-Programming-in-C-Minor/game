#ifndef GAME_TIRE_STACK_FACTORY_HPP
#define GAME_TIRE_STACK_FACTORY_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"
#include "string"

class TireStackFactory {
public:
    GameObject get(const std::string& name, const std::string& tag, Vector2d& pos, float scale);
};

#endif //GAME_TIRE_STACK_FACTORY_HPP
