#ifndef GAME_LEVELSFACTORY_HPP
#define GAME_LEVELSFACTORY_HPP

#include "scene.hpp"

class LevelsFactory {
public:
    [[nodiscard]] static std::shared_ptr<Scene> get_level1();

    [[nodiscard]] static std::shared_ptr<Scene> get_level2();
};

#endif
