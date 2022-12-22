#include "scenes/winning_factory.hpp"
#include <uiobject.hpp>
#include "objects/text_button_factory.hpp"
#include <components/sprite.hpp>
#include <components/text.hpp>
#include "listeners/back_listener.hpp"

std::shared_ptr<Scene> WinningFactory::get(std::vector<std::shared_ptr<Car>> cars) {
    auto scene = std::make_shared<Scene>(std::make_shared<Camera>(100.f, Transform{}, Color{255, 0, 0, 255}), "Winning Screen");

    int position = 0;
    for (auto &it: cars) {
        position++;

        auto text_ui_object = std::make_shared<UIObject>("position-" + std::to_string(position), "text", 30.f, 6.f,
                                                         scene->get_event_manager());
        auto text_object = std::make_shared<Text>(std::to_string(position) + ". " + it->get_name(),
                                                  "./assets/fonts/roboto/Roboto-Regular.ttf", 100, 10,
                                                  Color{255, 255, 255, 0}, Color{0, 0, 0, 1});
        text_ui_object->add_component(text_object);
        text_ui_object->transform.set_position(Vector2d{0, 80.f - position * 12.f});
        scene->gameobjects.push_back(text_ui_object);
    }

    scene->gameobjects.push_back(
            TextButtonFactory::get("back", "Back to menu", 80.f - cars.size() * 12.f - 26.f,
                                   scene->get_event_manager()));

    auto background_object = std::make_shared<UIObject>("background", "background", 200, 200,
                                                        scene->get_event_manager());
    auto background = std::make_shared<Sprite>("./assets/backgrounds/background.png", 1, 10.f);
    background_object->add_component(background);
    scene->gameobjects.push_back(background_object);

    auto listener = std::make_shared<GameObject>("winning-listener", "winning-listener");
    listener->add_component(std::make_shared<BackListener>(scene->get_event_manager()));
    scene->gameobjects.push_back(listener);

    return scene;
}
