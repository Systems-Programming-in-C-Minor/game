#ifndef GAME_GUARDRAIL_FACTORY_HPP
#define GAME_GUARDRAIL_FACTORY_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"
#include "string"

class GuardrailFactory {
public:
    GameObject get(const std::string& name, const std::string& tag, Vector2d& pos, double rotation, double scale);
};

#endif //GAME_GUARDRAIL_FACTORY_HPP
