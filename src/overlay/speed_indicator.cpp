#include "overlay/speed_indicator.hpp"
#include "utils/trigonometry.hpp"
#include <cmath>
#include <uiobject.hpp>
#include <scene.hpp>
#include <components/text.hpp>
#include <components/sprite.hpp>
#include <transform.hpp>
#include <iostream>
#include <cmath>

SpeedIndicator::SpeedIndicator(float velocity) : _velocity(velocity) {}

std::shared_ptr<GameObject> SpeedIndicator::get(EventManager &event_manager) {
    const auto speed_indicator_behaviour = std::shared_ptr<SpeedIndicator>(new SpeedIndicator());

    const auto ui_object_speed_indicator = std::make_shared<UIObject>("speed-indicator", "ui", 32, 24,
                                                                  event_manager,
                                                                  Transform{Vector2d{-80.f, -75}, Vector2d{}, 0.f});

    const auto speedometer_outer = std::make_shared<Sprite>("./assets/other/speedometer-outer.png", 1000, 6.f);
    const auto speedometer_pin =
            std::make_shared<UIObject>(
                "speed-indicator-pin",
                "ui",
                32,
                8,
                event_manager,
                Transform(
                        ui_object_speed_indicator->transform.get_position() + Vector2d{0, -10.f},
                        Vector2d{},
                        0));

    const auto speedometer_pin_sprite = std::make_shared<Sprite>("./assets/other/speedometer-pin.png", 1000);

    speedometer_pin->add_component(speedometer_pin_sprite);
    ui_object_speed_indicator->add_component(speed_indicator_behaviour);
    ui_object_speed_indicator->add_component(speedometer_outer);
    ui_object_speed_indicator->add_child(speedometer_pin);

    return ui_object_speed_indicator;
}

void SpeedIndicator::tick(GameObject &_game_object) {
    if (_game_object.get_tag() == "car") {
        _velocity = _game_object.get_component<RigidBody>()->get_forward_velocity().length();
    }

    if (_game_object.get_name() == "speed-indicator") {
        const auto speed_to_angle = static_cast<int>(std::round(_velocity * 3.6f));
        const auto angle = ( static_cast<float>(speed_to_angle) / 120.f ) * 120.f;
        const auto children = _game_object.get_children();
        for(auto &go : children){
            if(go->get_name() == "speed-indicator-pin"){
                go->transform.set_angle(-degrees_to_radians(angle));
            }
        }
    }
};
