#ifndef GAME_HIGH_SCORE_UI_FACTORY_HPP
#define GAME_HIGH_SCORE_UI_FACTORY_HPP

#include <uiobject.hpp>
#include <components/text.hpp>

class HighScoreUIFactory {
public:
    static std::shared_ptr<GameObject>
    get(const std::string &new_high_score, const std::string& level_name);
};

#endif //GAME_HIGH_SCORE_UI_FACTORY_HPP
