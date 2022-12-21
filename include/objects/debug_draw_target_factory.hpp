#ifndef GAME_DEBUG_DRAW_TARGET_FACTORY_HPP
#define GAME_DEBUG_DRAW_TARGET_FACTORY_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"

#include <vector>

class DebugDrawTargetFactory : public GameObject {
private:
    std::vector<Vector2d> _vectors;
    float _radius;
    float _randomize_radius;
public:
    explicit DebugDrawTargetFactory(std::vector<Vector2d> vectors, float radius = 5.0f, float randomize_radius = 2.5f);

    void get(Scene& scene);
};

#endif // GAME_DEBUG_DRAW_TARGET_FACTORY_HPP