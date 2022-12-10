#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"

class Car : public GameObject {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path);

    [[nodiscard]] float get_current_speed() const;

    [[nodiscard]] int get_current_round() const;

private:
    float _current_speed = 0;
    int _current_round = 0;
};

#endif //GAME_CAR_HPP
