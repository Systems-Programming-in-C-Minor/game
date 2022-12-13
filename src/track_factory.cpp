#include "track_factory.hpp"
#include "utils/trigonometry.hpp"
#include <utility>
#include <components/colliders/chaincollider.hpp>
#include <components/sprite.hpp>
#include <color.hpp>

std::shared_ptr<GameObject>
TrackFactory::get(const std::string &name, const std::string &tag, std::string sprite_path,
                  std::string track_inner_path, std::string track_outer_path, const std::shared_ptr<Scene> &scene) {
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(name, tag);
    std::shared_ptr<Sprite> sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, true, 1, 1, 6.f);
    obj->add_component(sprite);

    auto inner_collider = std::make_shared<ChainCollider>(track_inner_path, false, ColliderNormal::inwards);
    auto inner_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
    inner_rigidbody->set_collider(inner_collider);
    obj->add_component(inner_rigidbody);

    auto outer_collider = std::make_shared<ChainCollider>(track_outer_path);
    auto outer_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
    outer_rigidbody->set_collider(outer_collider);
    obj->add_component(outer_rigidbody);

    return obj;
}
