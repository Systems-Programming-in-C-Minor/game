#include "overlay/fps_indicator_factory.hpp"
#include "components/text.hpp"
#include "uiobject.hpp"
#include "scene.hpp"
#include "models/fps_indicator.hpp"

std::shared_ptr<GameObject> FpsIndicatorFactory::get(EventManager &event_manager) {
    const auto fps_indicator = std::make_shared<UIObject>("ui_fps_indicator", "ui", 4, 8, event_manager,
                                                             Transform{Vector2d{96.f, 92}, Vector2d{}, 0.f});
    fps_indicator->add_component(std::make_shared<Text>("0", "./assets/fonts/roboto/Roboto-Medium.ttf", 50, 1000,
                                                           Color{0, 255, 0, 255}, Color{0, 0, 0, 150}, 1));
    fps_indicator->add_component(std::make_shared<FpsIndicator>());

    return fps_indicator;
}
