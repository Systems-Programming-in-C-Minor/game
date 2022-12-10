#include "car/car.hpp"
#include "components/sprite.hpp"
#include "color.hpp"
#include "utils/trigonometry.hpp"

Car::Car(const std::string &name, const std::string &tag, std::string sprite_path) :
        GameObject(name, tag) {
    transform.set_scale(0.04f);
    transform.set_angle(degrees_to_radians(180));
    auto sprite =
            std::make_shared<Sprite>(std::move(sprite_path), Color(0, 0, 0, 0), false, false, 1, 1);

    add_component(sprite);
}

int Car::get_current_round() const {
    return _current_round;
}

float Car::get_current_speed() const {
    return _current_speed;
}
