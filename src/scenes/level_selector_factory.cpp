#include "scenes/level_selector_factory.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
#include "components/sprite.hpp"
#include "listeners/level_listener.hpp"
#include "objects/text_button_factory.hpp"

std::shared_ptr<Scene> LevelSelectorFactory::get(Mode mode) {
    auto scene = std::make_shared<Scene>(std::make_shared<Camera>(100.f, Transform{}, Color{255, 0, 0, 255}));

    scene->gameobjects.push_back(
            TextButtonFactory::get("level-1", "Race track", 40.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            TextButtonFactory::get("level-2", "Rainbow road", 0.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            TextButtonFactory::get("back", "Back to menu", -40.f, scene->get_event_manager()));

    auto background_object = std::make_shared<UIObject>("background", "background", 200, 200,
                                                        scene->get_event_manager());
    auto background = std::make_shared<Sprite>("./assets/backgrounds/background.png", 1, 10.f);
    background_object->add_component(background);
    scene->gameobjects.push_back(background_object);

    scene->gameobjects.push_back(std::make_shared<LevelListener>(scene->get_event_manager(), mode));

    return scene;
}

