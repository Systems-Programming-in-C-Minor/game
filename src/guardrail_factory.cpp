#include "guardrail_factory.hpp"

#include "transform.hpp"

GameObject GuardrailFactory::get(const std::string &name, const std::string &tag, Vector2d& pos, double rotation, double scale) {
    GameObject obj (name, tag);
    Transform transform(pos, rotation, scale);
    // TODO: Add transform to GameObject

    return obj;
}
