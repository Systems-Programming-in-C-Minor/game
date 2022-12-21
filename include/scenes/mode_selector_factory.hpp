
#ifndef GAME_MODE_SELECTOR_FACTORY_HPP
#define GAME_MODE_SELECTOR_FACTORY_HPP

#include <scene.hpp>
#include "uiobject.hpp"

class ModeSelectorFactory {
public:
    static std::shared_ptr<Scene> get();
};

#endif //GAME_MODE_SELECTOR_FACTORY_HPP
