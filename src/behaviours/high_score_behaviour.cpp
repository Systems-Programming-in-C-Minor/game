#include "behaviours/high_score_behaviour.hpp"
#include "race/behaviours/checkpoint_behaviour.hpp"

#include "chrono"
#include <string>
#include <iomanip>

HighScoreBehaviour::HighScoreBehaviour(EventManager &event_manager) : CheckpointListener(event_manager),
                                                                      _properties("high-scores.json"),
                                                                      _current_time(_set_current_time())
                                                                      {}

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

    auto current_high_score = _properties.get_property("milliseconds");
    if(!current_high_score.has_value() || std::stoll(current_high_score.value()) > diff)
    {
        _properties.set_property("level 1-milliseconds", std::to_string(diff));
        _properties.set_property("level 1-highscore", _format_lap_time(diff));
    }
}

std::string HighScoreBehaviour::_format_lap_time(long lap_time_milliseconds)
{
    std::chrono::milliseconds time(lap_time_milliseconds);

    auto minutes = std::chrono::duration_cast<std::chrono::minutes>(time).count();
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(time % std::chrono::minutes(1)).count();
    auto milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time % std::chrono::seconds(1)).count();

    std::stringstream ss;
    ss << std::setfill('0') << std::setw(2) << minutes << ":"
       << std::setfill('0') << std::setw(2) << seconds << "."
       << std::setfill('0') << std::setw(3) << milliseconds;

    std::string formatted_time = ss.str();
    return formatted_time;
}

long HighScoreBehaviour::_set_current_time()
{
    const auto now = std::chrono::system_clock::now();
    const auto now_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(now);
    auto epoch = now_ms.time_since_epoch();
    auto value = std::chrono::duration_cast<std::chrono::milliseconds>(epoch).count();
    return static_cast<long>(value);
}
