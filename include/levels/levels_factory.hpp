#ifndef GAME_LEVELSFACTORY_HPP
#define GAME_LEVELSFACTORY_HPP

#include "scene.hpp"
#include "level.hpp"

class LevelsFactory {
public:
    [[nodiscard]] static Level get_level1();

    [[nodiscard]] static Level get_level2();
};

#endif
