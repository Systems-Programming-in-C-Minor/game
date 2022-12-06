#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"

class Car : public GameObject {
public:
    Car(const std::string& name, const std::string& tag, const std::string sprite_path);
    [[nodiscard]] std::string get_sprite_path() const;
    void set_sprite_path(std::string sprite_path);
    [[nodiscard]] float get_current_speed() const;
    void set_current_speed(float speed);
    [[nodiscard]] int get_current_round() const;
    void set_current_round(int round);
private:
    std::string _sprite_path;
    float _current_speed;
    int _current_round;
};

#endif //GAME_CAR_HPP
