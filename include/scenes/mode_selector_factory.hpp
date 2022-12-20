
#ifndef GAME_MODE_SELECTOR_FACTORY_HPP
#define GAME_MODE_SELECTOR_FACTORY_HPP

#include <scene.hpp>
#include "uiobject.hpp"

class ModeSelectorFactory {
public:
    static std::shared_ptr<Scene> get();

private:
    static std::shared_ptr<UIObject>
    text_button(const std::string &name, const std::string &text, float position_y, EventManager &event_manager);
};

#endif //GAME_MODE_SELECTOR_FACTORY_HPP
