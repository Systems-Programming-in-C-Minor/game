#ifndef GAME_CHECKPOINT_FACTORY_HPP
#define GAME_CHECKPOINT_FACTORY_HPP

#include <optional>
#include "checkpoint.hpp"

class CheckpointFactory {
public:
    static std::shared_ptr<Checkpoint>
    get(bool is_finish_line, const std::optional<std::shared_ptr<Checkpoint>>& previous_checkpoint, Vector2d position,
        const std::shared_ptr<Scene> &scene, float width = 4.f);
};

#endif //GAME_CHECKPOINT_FACTORY_HPP
