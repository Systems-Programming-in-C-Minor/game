#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"
#include "checkpoint/checkpoint_behaviour.hpp"


class Car : public GameObject, public CheckpointBehaviour {
public:

    enum CarColor {
        Blue,
        Red,
        Yellow,
        Green,
        Orange,
        Pink,
    };

    Car(const std::string &name, CarColor color, Vector2d position, const std::shared_ptr<Scene> &scene);
};

#endif //GAME_CAR_HPP
