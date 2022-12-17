#include "guardrail_factory.hpp"

#include "transform.hpp"
#include "components/sprite.hpp"

GameObject GuardrailFactory::get(const std::string &name, const std::string &tag, Vector2d& pos, float rotation, float scale) {
    GameObject obj (name, tag, true, Transform { pos, Vector2d {}, rotation, scale});
    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("./assets/barriers/concrete.png", Color(0,0,0,0), false, false, 1, 1);
    obj.add_component(sprite);
    return obj;
}
