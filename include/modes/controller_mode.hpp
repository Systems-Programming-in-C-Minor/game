
#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <memory>
#include "scene.hpp"
#include "levels/level.hpp"

class ControllerMode {
public:
    static std::shared_ptr<Scene> get(const Level& level);
};

#endif //GAME_CONTROLLER_HPP
