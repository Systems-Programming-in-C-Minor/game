#include "car.hpp"

Car::Car(const std::string& name, const std::string& tag, const std::string sprite_path) : GameObject(name, tag),
    _sprite_path(sprite_path) {}

std::string Car::get_sprite_path() const {
    return _sprite_path;
}

void Car::set_sprite_path(std::string sprite_path) {
    _sprite_path = sprite_path;
}
