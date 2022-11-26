#include "checkpoint_factory.hpp"

Checkpoint CheckpointFactory::get(bool is_finish_line, Checkpoint *previous_checkpoint) {
    return Checkpoint(is_finish_line, previous_checkpoint);
}
