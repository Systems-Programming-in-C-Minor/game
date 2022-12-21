
#ifndef GAME_TEXT_BUTTON_HPP
#define GAME_TEXT_BUTTON_HPP

#include <scene.hpp>
#include <uiobject.hpp>

class TextButtonFactory {
public:
    static std::shared_ptr<UIObject>
    get(const std::string &name, const std::string &text, float position_y, EventManager &event_manager);
};

#endif //GAME_TEXT_BUTTON_HPP
