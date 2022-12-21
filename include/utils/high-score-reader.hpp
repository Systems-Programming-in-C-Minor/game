#ifndef GAME_HIGH_SCORE_READER_HPP
#define GAME_HIGH_SCORE_READER_HPP

#include <string>
#include <memory>
#include <iomanip>
#include <chrono>

#include "storage/json_properties.hpp"

inline static std::string format_lap_time(long lap_time_milliseconds)
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

inline static std::string get_high_score(const std::string &level, const std::shared_ptr<JsonProperties>& properties)
{
    if(properties->get_property(level).has_value())
    {
        long high_score = std::stol(properties->get_property(level).value());
        return "High score: " + format_lap_time(high_score);
    }
    return "No high score yet";
}

#endif //GAME_HIGH_SCORE_READER_HPP
