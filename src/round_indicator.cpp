#include "round_indicator.hpp"

RoundIndicator::RoundIndicator(const Text& text) :
        _text(text) {}

Text RoundIndicator::get_text() const {
    return _text;
}

void RoundIndicator::set_text(const Text& text) {
    _text = text;
}

//GameObject RoundIndicator::get(GameObject &playerCar) {
//    //TODO
//}
