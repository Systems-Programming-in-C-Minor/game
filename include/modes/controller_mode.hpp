
#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include <memory>
#include "scene.hpp"
#include "race/models/level.hpp"

class ControllerMode {
public:
    static std::shared_ptr<Scene> get(const RaceLevel& level);
};

#endif //GAME_CONTROLLER_HPP
