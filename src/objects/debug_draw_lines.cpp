#include "objects/debug_draw_lines.hpp"
#include "debug.hpp"

DebugDrawLines::DebugDrawLines(std::vector<Vector2d> vectors)
    : GameObject("ui_debug_draw_lines", "ui_debug", Transform{}), _vectors(std::move(vectors))
{
    const Vector2d start_vertex = _vectors[0];
    _vectors.push_back(start_vertex);
}

void DebugDrawLines::tick()
{
    for (int i = 1; i < static_cast<int>(_vectors.size()); ++i) {
        Debug::draw_line(_vectors[i - 1], _vectors[i], Color{ 0, 0, 255, 0 });
    }
}