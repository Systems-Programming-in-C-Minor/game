#ifndef GAME_GUARDRAIL_FACTORY_HPP
#define GAME_GUARDRAIL_FACTORY_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"
#include "string"

class GuardrailFactory {
public:
    static std::shared_ptr<GameObject> get(Vector2d pos, float rotation, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_GUARDRAIL_FACTORY_HPP
