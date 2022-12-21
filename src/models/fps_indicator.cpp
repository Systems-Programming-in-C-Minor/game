#include "models/fps_indicator.hpp"
#include <components/text.hpp>
#include <global.hpp>

void FpsIndicator::tick(GameObject &_game_object) {
    const auto text = game_object->get_component<Text>();
    const unsigned long fps = Global::get_instance()->get_engine().get_fps();
    text->set_text(std::to_string(fps));
}

void FpsIndicator::on_key_pressed(const KeyPressedEvent& event)
{
    const auto alt_pressed = Global::get_instance()->input.get_key(ALT_LEFT);

    switch (event.key) {
    case D: {
        if (alt_pressed) {
            if(_is_visible){
				game_object->get_component<Text>()->set_foreground_color(Color{0, 0, 0, 1});
                game_object->get_component<Text>()->set_background_color(Color{0, 0, 0, 1});
                _is_visible = !_is_visible;
            } else {
				game_object->get_component<Text>()->set_foreground_color(Color{0, 255, 0, 255});
                game_object->get_component<Text>()->set_background_color(Color{0, 0, 0, 150});
                _is_visible = !_is_visible;
            }
        }
        break;
    }
    default:
        break;
    }
}