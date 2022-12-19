#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"
#include "race/behaviours/drive_behaviour.hpp"

class Car : public GameObject, public DriveBehaviour {
public:
    enum CarColor {
        Red,
        Blue,
        Yellow,
        Green,
        Orange,
        Pink,
        Purple,
        Black
    };

    Car(const std::string &name, CarColor color, Vector2d position, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_CAR_HPP
