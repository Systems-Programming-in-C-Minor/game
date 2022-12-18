#include "levels/track_factory.hpp"

#include <utility>
#include <components/colliders/chaincollider.hpp>
#include <components/sprite.hpp>
#include <color.hpp>

std::shared_ptr<GameObject>
TrackFactory::get(const std::string &name, const std::string &tag, std::string sprite_path, std::string bg_sprite_path,
                  const std::string &track_inner_path, const std::string &track_outer_path,
                  const std::shared_ptr<Scene> &scene) {
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(name, tag);
    std::shared_ptr<Sprite> sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, true, 1, 1, 12.f);
    obj->add_component(sprite);

    std::shared_ptr<GameObject> obj_child = std::make_shared<GameObject>(name + "_bg", tag, true, Transform{ Vector2d{}, Vector2d{}, 0, 2.f});
    std::shared_ptr<Sprite> sprite_bg =
        std::make_shared<Sprite>(std::move(bg_sprite_path), Color(0, 0, 0, 0),false, true, 1, 0, 6.f);
    obj_child->add_component(sprite_bg);
    obj->add_child(obj_child);

    auto inner_collider = std::make_shared<ChainCollider>(track_inner_path, false);
    auto inner_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
    inner_rigidbody->set_collider(inner_collider);
    obj->add_component(inner_rigidbody);

    auto outer_collider = std::make_shared<ChainCollider>(track_outer_path, false, ColliderNormal::inwards);
    auto outer_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
    outer_rigidbody->set_collider(outer_collider);
    obj->add_component(outer_rigidbody);

    return obj;
}
