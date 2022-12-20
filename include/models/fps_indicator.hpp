
#ifndef GAME_FPS_INDICATOR_HPP
#define GAME_FPS_INDICATOR_HPP

#include <gameobject.hpp>
#include <interfaces/itickable.hpp>

class FpsIndicator : public Component, public ITickable {
    void tick(GameObject &_game_object) override;
};

#endif //GAME_FPS_INDICATOR_HPP
