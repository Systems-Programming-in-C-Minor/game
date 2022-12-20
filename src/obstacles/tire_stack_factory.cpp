#include "obstacles/tire_stack_factory.hpp"
#include "transform.hpp"
#include "components/sprite.hpp"
#include "components/colliders/boxcollider.hpp"

std::shared_ptr<GameObject> TireStackFactory::get(Vector2d pos, const std::shared_ptr<Scene> &scene) {
    auto obj = std::make_shared<GameObject>("tire-stack", "tire-stack");

    const auto sprite = std::make_shared<Sprite>("./assets/obstacles/tire_stack.png", 20, 200.f);
    obj->add_component(sprite);

    auto collider = std::make_shared<BoxCollider>(1.4f, 1.4f);
    auto rigid_body = std::make_shared<RigidBody>(*scene, 20, BodyType::static_body, pos, 1.f);
    rigid_body->set_collider(collider);
    obj->add_component(rigid_body);

    return obj;
}
