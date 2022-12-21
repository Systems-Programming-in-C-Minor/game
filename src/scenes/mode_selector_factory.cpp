#include "scenes/mode_selector_factory.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
#include "components/sprite.hpp"
#include "listeners/mode_listener.hpp"


std::shared_ptr<Scene> ModeSelectorFactory::get() {
    auto scene = std::make_shared<Scene>(std::make_shared<Camera>(100.f, Transform{}));
    auto properties = std::make_shared<JsonProperties>("high-scores.json");

    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("singleplayer", "Singleplayer", 60.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("coop", "Coop (2 players)", 20.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("controller", "Controller (1-8 players)", -20.f,
                                             scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::text_button("multiplayer", "Multiplayer", -60.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::high_score_text("level-1-highscore", get_high_score("level 1", properties),-75.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            ModeSelectorFactory::high_score_text("level-2-highscore", get_high_score("level 2", properties),-90.f, scene->get_event_manager()));

    auto background_object = std::make_shared<GameObject>("background", "background");
    auto background = std::make_shared<Sprite>("./assets/backgrounds/background.png", 0, 100.f);
    background_object->add_component(background);
    background_object->transform.set_scale(2.f);
    scene->gameobjects.push_back(background_object);

    scene->gameobjects.push_back(std::make_shared<ModeListener>(scene->get_event_manager()));

    return scene;
}

std::shared_ptr<UIObject>
ModeSelectorFactory::text_button(const std::string &name, const std::string &text, float position_y,
                                 EventManager &event_manager) {


    auto ui_object = std::make_shared<UIObject>(name, "button", 100.f, 45.f, event_manager);
    auto button = std::make_shared<Sprite>("./assets/ui/empty-button.png", 5);
    ui_object->add_component(button);

    auto text_ui_object = std::make_shared<UIObject>(name + "-text", "text", 50.f, 8.f, event_manager);
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

std::shared_ptr<UIObject> ModeSelectorFactory::high_score_text(const std::string &name, const std::string &text, float position_y,
                                                               EventManager &event_manager) {

    auto high_score_ui = std::make_shared<UIObject>(name, "high-score", 40.f, 18.f, event_manager);
    auto high_score_text_object = std::make_shared<Text>(text, "./assets/fonts/roboto/Roboto-Medium.ttf", 1000, 10,
                                                         Color{255, 255, 255, 0}, Color{0, 0, 0, 1});
    high_score_ui->add_component(high_score_text_object);
    high_score_ui->transform.set_position(Vector2d{0, position_y});

    return high_score_ui;
}

std::string ModeSelectorFactory::get_high_score(const std::string &level, const std::shared_ptr<JsonProperties>& properties) {
    if(properties->get_property(level + "-highscore").has_value())
        return "High score for " + level + ":" + properties->get_property(level + "-highscore").value();

    return "No high score yet for " + level;
}
