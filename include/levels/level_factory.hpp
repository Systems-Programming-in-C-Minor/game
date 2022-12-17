
#ifndef GAME_LEVEL_FACTORY_HPP
#define GAME_LEVEL_FACTORY_HPP

#include <scene.hpp>
#include "level.hpp"

class LevelFactory {
public:
    virtual Level get() = 0;

};

#endif //GAME_LEVEL_FACTORY_HPP
