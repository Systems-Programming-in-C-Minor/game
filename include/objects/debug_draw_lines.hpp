#ifndef GAME_DEBUG_DRAW_LINES_HPP
#define GAME_DEBUG_DRAW_LINES_HPP

#include "gameobject.hpp"
#include "vector2d.hpp"

#include <vector>

class DebugDrawLines : public GameObject {
private:
    std::vector<Vector2d> _vectors;
public:
    explicit DebugDrawLines(std::vector<Vector2d> vectors);
    void tick() override;
};

#endif // GAME_DEBUG_DRAW_LINES_HPP