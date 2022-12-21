#include "scenes/mode_selector_factory.hpp"
#include "uiobject.hpp"
#include "components/text.hpp"
#include "components/sprite.hpp"
#include "listeners/mode_listener.hpp"
#include "objects/text_button_factory.hpp"

std::shared_ptr<Scene> ModeSelectorFactory::get() {
    auto scene = std::make_shared<Scene>(std::make_shared<Camera>(100.f, Transform{}));

    scene->gameobjects.push_back(
            TextButtonFactory::get("singleplayer", "Singleplayer", 60.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            TextButtonFactory::get("coop", "Coop (2 players)", 20.f, scene->get_event_manager()));
    scene->gameobjects.push_back(
            TextButtonFactory::get("controller", "Controller (1-8 players)", -20.f,
                                   scene->get_event_manager()));
    scene->gameobjects.push_back(
            TextButtonFactory::get("multiplayer", "Multiplayer", -60.f, scene->get_event_manager()));

    auto background_object = std::make_shared<GameObject>("background", "background");
    auto background = std::make_shared<Sprite>("./assets/backgrounds/background.png", 0, 100.f);
    background_object->add_component(background);
    background_object->transform.set_scale(2.f);
    scene->gameobjects.push_back(background_object);

    scene->gameobjects.push_back(std::make_shared<ModeListener>(scene->get_event_manager()));

    return scene;
}

