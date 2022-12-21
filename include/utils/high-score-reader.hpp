#ifndef GAME_HIGH_SCORE_READER_HPP
#define GAME_HIGH_SCORE_READER_HPP

#include <string>
#include <memory>
#include "storage/json_properties.hpp"


inline static std::string get_high_score(const std::string &level, const std::shared_ptr<JsonProperties>& properties)
{
    if(properties->get_property(level + "-highscore").has_value())
        return "High score: " + properties->get_property(level + "-highscore").value();

    return "No high score yet";
}
#endif //GAME_HIGH_SCORE_READER_HPP
