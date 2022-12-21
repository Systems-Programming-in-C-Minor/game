#include "colliders/track_factory.hpp"
#include <utility>
#include "components/colliders/chaincollider.hpp"
#include "components/sprite.hpp"

std::shared_ptr<GameObject>
TrackFactory::get(const std::string &name, const std::shared_ptr<Scene> &scene, std::string sprite_path, float pixels_to_meters,
                  const std::vector<std::string> &track_inner_paths,
                  std::optional<std::string> track_outer_path, std::optional<std::string> bg_sprite_path) {
    std::shared_ptr<GameObject> obj = std::make_shared<GameObject>(name, "track");
    std::shared_ptr<Sprite> sprite =
            std::make_shared<Sprite>(std::move(sprite_path), 1, pixels_to_meters);
    obj->add_component(sprite);

    if (bg_sprite_path.has_value()) {
        std::shared_ptr<GameObject> obj_child = std::make_shared<GameObject>(name + "_bg", "track",
                                                                             Transform{Vector2d{}, Vector2d{}, 0, 2.f});
        std::shared_ptr<Sprite> sprite_bg = std::make_shared<Sprite>(std::move(bg_sprite_path.value()), 0, 6.f);
        obj_child->add_component(sprite_bg);
        obj->add_child(obj_child);
    }

    for (const auto &track_inner_path: track_inner_paths) {
        auto inner_collider = std::make_shared<ChainCollider>(track_inner_path, false);
        auto inner_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
        inner_rigidbody->set_collider(inner_collider);
        obj->add_component(inner_rigidbody);
    }

    if (track_outer_path.has_value()) {
        auto outer_collider = std::make_shared<ChainCollider>(track_outer_path.value(), false, ColliderNormal::inwards);
        auto outer_rigidbody = std::make_shared<RigidBody>(*scene, 6, BodyType::static_body, Vector2d{0.f, 0.f}, 1.0f);
        outer_rigidbody->set_collider(outer_collider);
        obj->add_component(outer_rigidbody);
    }

    return obj;
}
