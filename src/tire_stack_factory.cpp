#include "tire_stack_factory.hpp"
#include "transform.hpp"
#include "components/sprite.hpp"

std::shared_ptr<GameObject>
TireStackFactory::get(const std::string &name, const std::string &tag, Vector2d &pos, float scale) {
    std::shared_ptr<GameObject> obj =
            std::make_shared<GameObject>(name, tag, true, Transform{pos, Vector2d{}, 0.0f, scale});
    std::shared_ptr<Sprite> sprite =
            std::make_shared<Sprite>("../assets/barriers/tire_stack.png", Color(0, 0, 0, 0), false, false, 1, 1);
    obj->add_component(sprite);
    return obj;
}
