#include "guardrail_factory.hpp"

#include "transform.hpp"

GameObject GuardrailFactory::get(const std::string &name, const std::string &tag, Vector2d& pos, double rotation, double scale) {
    return GameObject(name, tag);
    // TODO: Add Transform in gameobject
}
