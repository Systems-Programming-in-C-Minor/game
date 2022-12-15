#include <iomanip>
#include "checkpoint/checkpoint_factory.hpp"
#include "components/colliders/boxcollider.hpp"

std::shared_ptr<Checkpoint>
CheckpointFactory::get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>> &previous_checkpoint,
                       const Vector2d position,
                       const std::shared_ptr<Scene> &scene, const float width) {

    const auto collider = std::make_shared<BoxCollider>(width, .2f, true);
    const auto body = std::make_shared<RigidBody>(*scene, 2, BodyType::static_body, position, 1.0f);
    body->set_collider(collider);

    auto name = "checkpoint" + std::to_string(position.x).substr(0, std::to_string(position.x).find('.') + 2) + "_" +
                std::to_string(position.y).substr(0, std::to_string(position.y).find('.') + 2);

    auto checkpoint = std::make_shared<Checkpoint>(name, "checkpoint", is_finish_line, previous_checkpoint);
    checkpoint->add_component(body);

    return checkpoint;
}
