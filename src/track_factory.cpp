#include "track_factory.hpp"
#include "utils/trigonometry.hpp"
#include <utility>
#include <components/colliders/chaincollider.hpp>
#include <components/sprite.hpp>
#include <color.hpp>

std::shared_ptr<GameObject>
TrackFactory::get(const std::string &name, const std::string &tag, std::string sprite_path,  std::string collider_path,
                  const std::shared_ptr<Scene> &scene) {
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(name, tag);
    std::shared_ptr<Sprite> sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, true, 1, 1, 6.f);
    obj->add_component(sprite);

    auto chain_collider = std::make_shared<ChainCollider>(collider_path);
    auto chain_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{ 0.f, 0.f}, 1.0f);
    chain_rigidbody->set_collider(chain_collider);
    obj->transform.set_angle(degrees_to_radians(180));
    obj->add_component(chain_rigidbody);

    return obj;
}
