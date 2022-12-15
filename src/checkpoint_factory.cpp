#include "checkpoint_factory.hpp"
#include "components/colliders/boxcollider.hpp"

std::shared_ptr<Checkpoint>
CheckpointFactory::get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>>& previous_checkpoint, const Vector2d position,
                       const std::shared_ptr<Scene> &scene, const float width) {

    const auto collider = std::make_shared<BoxCollider>(width, .5f, true);
    const auto body = std::make_shared<RigidBody>(*scene, 2, BodyType::static_body, position, 1.0f);
    body->set_collider(collider);

    auto checkpoint = std::make_shared<Checkpoint>("checkpoint", "checkpoint", is_finish_line, previous_checkpoint);
    checkpoint->add_component(body);

    return checkpoint;
}
