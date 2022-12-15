#include "checkpoint/checkpoint_behaviour.hpp"

CheckpointBehaviour::CheckpointBehaviour(EventManager &event_manager) : ColliderListener(event_manager) {}

void CheckpointBehaviour::on_collider_entry(const ColliderEntryEvent &event) {
    check_and_set_checkpoint(event.collider_a->game_object);
    check_and_set_checkpoint(event.collider_b->game_object);
}

void CheckpointBehaviour::on_collider_exit(const ColliderExitEvent &event) {}

void CheckpointBehaviour::check_and_set_checkpoint(GameObject *game_object) {
    if (game_object->get_tag() == "checkpoint") {
        auto checkpoint = reinterpret_cast<Checkpoint *>(game_object);
        auto first_checkpoint = !checkpoint->previous_checkpoint.has_value() && !_reached.has_value();
        auto new_checkpoint = checkpoint->previous_checkpoint.has_value() && _reached.has_value() &&
                              checkpoint->previous_checkpoint.value()->get_name() == _reached.value()->get_name();
        if (new_checkpoint || first_checkpoint)
            _reached = std::make_shared<Checkpoint>(*checkpoint);
    }
}
