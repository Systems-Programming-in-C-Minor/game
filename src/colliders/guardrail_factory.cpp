#include "colliders/guardrail_factory.hpp"
#include "transform.hpp"
#include "components/sprite.hpp"
#include "components/colliders/boxcollider.hpp"
#include <utils/trigonometry.hpp>

std::shared_ptr<GameObject> GuardrailFactory::get(Vector2d pos, float rotation, const std::shared_ptr<Scene> &scene) {
    auto obj = std::make_shared<GameObject>("guard-rail", "guard-rail");
    std::shared_ptr<Sprite> sprite = std::make_shared<Sprite>("./assets/obstacles/concrete.png", 20, 40.f);

    auto collider = std::make_shared<BoxCollider>(7.8f, 1.2f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, 20, BodyType::static_body, pos);
    rigid_body->set_collider(collider);
    rigid_body->set_angle(degrees_to_radians(rotation));
    obj->add_component(rigid_body);

    obj->add_component(sprite);
    return obj;
}
