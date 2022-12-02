#ifndef GAME_ROUND_INDICATOR_HPP
#define GAME_ROUND_INDICATOR_HPP

#include "uiobjects/text.hpp"
#include "gameobject.hpp"

class RoundIndicator {
public:
    RoundIndicator(const Text& text);
    [[nodiscard]] Text get_text() const;
    void set_text(const Text& text);
//    GameObject get(GameObject& playerCar);
private:
    Text _text;
};

#endif //GAME_ROUND_INDICATOR_HPP
