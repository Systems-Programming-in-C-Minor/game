#include "scenes/mode_selecotor_factory.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
#include "components/sprite.hpp"

std::shared_ptr<Scene> ModeSelectorFactory::get() {
    auto scene = std::make_shared<Scene>(std::make_shared<Camera>(100.f, Transform{}));

    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("singleplayer", "Singleplayer", 60.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("coop", "Coop (2 players)", 20.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("controller", "Controller (1-8 players)", -20.f,
                                             scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("multiplayer", "Multiplayer", -60.f, scene->get_event_manager()));

    auto background_object = std::make_shared<GameObject>("background", "background");
    auto background = std::make_shared<Sprite>("./assets/backgrounds/background.png", 0, 100.f);
    background_object->add_component(background);
    background_object->transform.set_scale(2.f);
    scene->gameobjects.push_back(background_object);

    return scene;
}

std::shared_ptr<UIObject>
ModeSelectorFactory::text_button(const std::string &name, const std::string &text, float position_y,
                                 EventManager &event_manager) {


    auto ui_object = std::make_shared<UIObject>(name, "button", 100.f, 45.f, event_manager);
    auto button = std::make_shared<Sprite>("./assets/ui/empty-button.png", 5);
    ui_object->add_component(button);

    auto text_ui_object = std::make_shared<UIObject>(name, "button", 50.f, 8.f, event_manager);
    auto text_object = std::make_shared<Text>(text, "./assets/fonts/roboto/Roboto-Medium.ttf", 1000, 10,
                                              Color{255, 255, 255, 0}, Color{0, 0, 0, 1});
    text_ui_object->add_component(text_object);
    ui_object->add_child(text_ui_object);

    auto new_position = Vector2d{0, position_y};
    ui_object->transform.set_position(new_position);
    auto new_text_position = Vector2d{0, position_y + 2};
    text_ui_object->transform.set_position(new_text_position);

    return ui_object;
}
