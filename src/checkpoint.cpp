#include <optional>
#include <utility>
#include "checkpoint.hpp"

Checkpoint::Checkpoint(const std::string &name, const std::string &tag, const bool is_finish_line,
                       std::optional<std::shared_ptr<Checkpoint>> previous_checkpoint) : GameObject(name, tag),
                                                                         _is_finish_line(is_finish_line),
                                                                         _previous_checkpoint(std::move(previous_checkpoint)) {}
