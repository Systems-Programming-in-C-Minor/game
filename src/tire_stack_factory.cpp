#include "tire_stack_factory.hpp"

GameObject TireStackFactory::get(const std::string &name, const std::string &tag, Vector2d &pos, double scale) {
    return GameObject(name, tag);
    // TODO: Add transform
}
