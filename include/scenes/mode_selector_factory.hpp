
#ifndef GAME_MODE_SELECTOR_FACTORY_HPP
#define GAME_MODE_SELECTOR_FACTORY_HPP

#include <scene.hpp>
#include "uiobject.hpp"
#include "storage/json_properties.hpp"
#include <string>

class ModeSelectorFactory {
public:
    static std::shared_ptr<Scene> get();
private:
    static std::shared_ptr<UIObject> text_button(const std::string &name, const std::string &text, float position_y, EventManager &event_manager);
    static std::shared_ptr<UIObject>high_score_text(const std::string &name, const std::string &text, float position_y, EventManager &event_manager);
    static std::string get_high_score(const std::string &level, const std::shared_ptr<JsonProperties>& properties);
};

#endif //GAME_MODE_SELECTOR_FACTORY_HPP
