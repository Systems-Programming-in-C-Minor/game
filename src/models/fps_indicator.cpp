#include "models/fps_indicator.hpp"
#include <components/text.hpp>
#include <global.hpp>

void FpsIndicator::tick(GameObject &_game_object) {
    const auto text = game_object->get_component<Text>();
    const unsigned long fps = Global::get_instance()->get_engine().get_fps();
    text->set_text(std::to_string(fps));
}