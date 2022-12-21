#ifndef GAME_SPEED_INDICATOR_HPP
#define GAME_SPEED_INDICATOR_HPP

#include "race/objects/car.hpp"
#include "managers/event_manager.hpp"

class SpeedIndicator : public Component, public ITickable {
private:
    float _velocity;

    explicit SpeedIndicator(float velocity = 0.f);

public:
    static std::shared_ptr<GameObject> get(EventManager &event_manager);

    void tick(GameObject &_game_object) override;
};

#endif //GAME_SPEED_INDICATOR_HPP
