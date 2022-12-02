#include "tire_stack_factory.hpp"

#include "transform.hpp"

GameObject TireStackFactory::get(const std::string &name, const std::string &tag, Vector2d &pos, double scale) {
    GameObject obj (name, tag);
    Transform transform(pos, 0, scale);
    // TODO: Add transform to GameObject

    return obj;
}
