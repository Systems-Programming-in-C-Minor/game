#ifndef GAME_CHECKPOINT_HPP
#define GAME_CHECKPOINT_HPP

#include "gameobject.hpp"

class Checkpoint : public GameObject {
public:
    Checkpoint(const std::string& name, const std::string& tag, const bool is_finish_line, Checkpoint *previous_checkpoint);
    [[nodiscard]] bool get_is_finish_line() const;
    [[nodiscard]] Checkpoint* get_previous_checkpoint() const;
    void set_is_finish_line(bool is_finish_line);
    void set_previous_checkpoint(Checkpoint *previous_checkpoint);
private:
    bool _is_finish_line;
    Checkpoint *_previous_checkpoint;
};

#endif //GAME_CHECKPOINT_HPP
