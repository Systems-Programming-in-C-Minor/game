#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"

class Car : public GameObject {
public:
    Car(const std::string& name, const std::string& tag, const std::string sprite_path);
    [[nodiscard]] std::string get_sprite_path() const;
    void set_sprite_path(std::string sprite_path);
private:
    std::string _sprite_path;
};

#endif //GAME_CAR_HPP
