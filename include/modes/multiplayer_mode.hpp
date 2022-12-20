
#ifndef GAME_MULTI_PLAYER_HPP
#define GAME_MULTI_PLAYER_HPP

#include <memory>
#include "scene.hpp"
#include "race/models/level.hpp"

class MultiplayerMode {
public:
    static std::shared_ptr<Scene> get(const RaceLevel& level);
};

#endif //GAME_MULTI_PLAYER_HPP
