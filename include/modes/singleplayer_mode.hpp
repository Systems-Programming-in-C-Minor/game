
#ifndef GAME_SINGLE_PLAYER_HPP
#define GAME_SINGLE_PLAYER_HPP

#include <memory>
#include "scene.hpp"
#include "race/models/level.hpp"

class SingleplayerMode {
public:
    static std::shared_ptr<Scene> get(const RaceLevel& level);
};

#endif //GAME_SINGLE_PLAYER_HPP
