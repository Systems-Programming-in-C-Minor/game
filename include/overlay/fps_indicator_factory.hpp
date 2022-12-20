
#ifndef GAME_FPS_INDICATOR_FACTORY_HPP
#define GAME_FPS_INDICATOR_FACTORY_HPP

#include <memory>
#include <vector>
#include <gameobject.hpp>

class EventManager;

class FpsIndicatorFactory {
public:
    static std::shared_ptr<GameObject> get(EventManager &event_manager);
};

#endif //GAME_FPS_INDICATOR_FACTORY_HPP
