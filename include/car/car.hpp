#ifndef GAME_CAR_HPP
#define GAME_CAR_HPP

#include "string"
#include "gameobject.hpp"
#include "checkpoint/checkpoint_behaviour.hpp"

class Car : public GameObject, public CheckpointBehaviour {
public:
    Car(const std::string &name, const std::string &tag, std::string sprite_path, const std::shared_ptr<Scene> &scene,
        int order_in_layer = 10);
};

#endif //GAME_CAR_HPP
