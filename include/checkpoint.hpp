#ifndef GAME_CHECKPOINT_HPP
#define GAME_CHECKPOINT_HPP

class Checkpoint {
public:
    Checkpoint(bool is_finish_line, Checkpoint *previous_checkpoint);
    [[nodiscard]] bool get_is_finish_line() const;
    [[nodiscard]] Checkpoint* get_previous_checkpoint() const;
    void set_is_finish_line(bool is_finish_line);
    void set_previous_checkpoint(Checkpoint *previous_checkpoint);
private:
    bool _is_finish_line;
    Checkpoint *_previous_checkpoint;
};

#endif //GAME_CHECKPOINT_HPP
