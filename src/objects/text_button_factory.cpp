#include "objects/text_button_factory.hpp"
#include <components/sprite.hpp>
#include <components/text.hpp>

std::shared_ptr<UIObject>
TextButtonFactory::get(const std::string &name, const std::string &text, float position_y,
                                 EventManager &event_manager) {


    auto ui_object = std::make_shared<UIObject>(name, "button", 100.f, 45.f, event_manager);
    auto button = std::make_shared<Sprite>("./assets/ui/empty-button.png", 5);
    ui_object->add_component(button);

    auto text_ui_object = std::make_shared<UIObject>(name + "-text", "text", 50.f, 8.f, event_manager);
    auto text_object = std::make_shared<Text>(text, "./assets/fonts/roboto/Roboto-Medium.ttf", 100, 10,
                                              Color{255, 255, 255, 0}, Color{0, 0, 0, 1});
    text_ui_object->add_component(text_object);
    ui_object->add_child(text_ui_object);

    auto new_position = Vector2d{0, position_y};
    ui_object->transform.set_position(new_position);
    auto new_text_position = Vector2d{0, position_y + 2};
    text_ui_object->transform.set_position(new_text_position);

    return ui_object;
}

