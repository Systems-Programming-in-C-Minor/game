
#ifndef GAME_LEVEL_SELECTOR_FACTORY_HPP
#define GAME_LEVEL_SELECTOR_FACTORY_HPP

#include <scene.hpp>
#include "uiobject.hpp"
#include "listeners/level_listener.hpp"

class LevelSelectorFactory {
public:
    static std::shared_ptr<Scene> get(Mode mode);
};

#endif //GAME_LEVEL_SELECTOR_FACTORY_HPP
