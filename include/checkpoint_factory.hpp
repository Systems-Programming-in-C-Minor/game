#ifndef GAME_CHECKPOINT_FACTORY_HPP
#define GAME_CHECKPOINT_FACTORY_HPP

#include "checkpoint.hpp"

class CheckpointFactory {
    Checkpoint get(const std::string& name, const std::string& tag, const bool is_finish_line, Checkpoint *previous_checkpoint);
};

#endif //GAME_CHECKPOINT_FACTORY_HPP
