#include "behaviours/high_score_behaviour.hpp"
#include "race/behaviours/checkpoint_behaviour.hpp"

#include "chrono"
#include <string>

HighScoreBehaviour::HighScoreBehaviour(EventManager &event_manager) : CheckpointListener(event_manager),
                                                                      _properties("high-scores.json"),
                                                                      _current_time(_set_current_time())
{
    _global = Global::get_instance();
}

void HighScoreBehaviour::on_checkpoint_lapped(const CheckpointLappedEvent &event)
{
    if(event.checkpoint_behaviour->game_object != game_object)
        return;

    long lap_time = event.checkpoint_behaviour->get_lap_times().back();
    check_high_scores(lap_time);
    _current_time = _set_current_time();
}


void HighScoreBehaviour::check_high_scores(long lap_time)
{
    long diff = lap_time - _current_time;
    std::string level_name = _global->get_active_scene().get_name();

    auto current_high_score = _properties.get_property(level_name);
    if(!current_high_score.has_value() || std::stoll(current_high_score.value()) > diff)
    {
        _properties.set_property(level_name, std::to_string(diff));
    }
}

long HighScoreBehaviour::_set_current_time()
{
    const auto now = std::chrono::system_clock::now();
    const auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
    return static_cast<long>(value);
}
