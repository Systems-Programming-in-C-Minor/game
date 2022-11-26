#include "checkpoint_factory.hpp"

Checkpoint CheckpointFactory::get(const std::string& name, const std::string& tag, const bool is_finish_line, Checkpoint *previous_checkpoint) {
    return Checkpoint(name, tag, is_finish_line, previous_checkpoint);
}
