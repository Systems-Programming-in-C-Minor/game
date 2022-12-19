#ifndef GAME_LEVELSFACTORY_HPP
#define GAME_LEVELSFACTORY_HPP

#include "scene.hpp"
#include "../../../engine/include/race/models/level.hpp"

class LevelsFactory {
public:
    [[nodiscard]] static RaceLevel get_level1();

    [[nodiscard]] static RaceLevel get_level2();
};

#endif
