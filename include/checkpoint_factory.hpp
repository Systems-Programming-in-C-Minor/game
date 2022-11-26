#ifndef GAME_CHECKPOINT_FACTORY_HPP
#define GAME_CHECKPOINT_FACTORY_HPP

#include "checkpoint.hpp"

class CheckpointFactory {
    Checkpoint get(bool is_finish_line, Checkpoint *previous_checkpoint);
};

#endif //GAME_CHECKPOINT_FACTORY_HPP
