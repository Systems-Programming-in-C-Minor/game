#ifndef GAME_HIGH_SCORE_BEHAVIOUR_HPP
#define GAME_HIGH_SCORE_BEHAVIOUR_HPP

#include "components/component.hpp"
#include "listeners/collider_listener.hpp"
#include "storage/json_properties.hpp"
#include "listeners/checkpoint_listener.hpp"
#include "global.hpp"

class HighScoreBehaviour : public Component, public CheckpointListener {
public:
    explicit HighScoreBehaviour(EventManager &event_manager);
    void on_checkpoint_lapped(const CheckpointLappedEvent &event) override;
    void check_high_scores(long lap_time);
private:
    static long _set_current_time();
    JsonProperties _properties;
    long _current_time;
    Global *_global;
};

#endif //GAME_HIGH_SCORE_BEHAVIOUR_HPP
