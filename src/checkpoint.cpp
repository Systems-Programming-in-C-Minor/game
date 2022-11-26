#include "checkpoint.hpp"

Checkpoint::Checkpoint(const std::string& name, const std::string& tag, const bool is_finish_line, Checkpoint *previous_checkpoint) : GameObject(name, tag),
    _is_finish_line(is_finish_line),
    _previous_checkpoint(previous_checkpoint) {}

bool Checkpoint::get_is_finish_line() const {
    return _is_finish_line;
}

Checkpoint* Checkpoint::get_previous_checkpoint() const {
    return _previous_checkpoint;
}

void Checkpoint::set_is_finish_line(bool is_finish_line) {
    _is_finish_line = is_finish_line;
}

void Checkpoint::set_previous_checkpoint(Checkpoint *previous_checkpoint) {
    _previous_checkpoint = previous_checkpoint;
}
