
#ifndef GAME_SINGLE_PLAYER_HPP
#define GAME_SINGLE_PLAYER_HPP

#include <memory>
#include "scene.hpp"
#include "levels/level.hpp"

class SingleplayerMode {
public:
    static std::shared_ptr<Scene> get(const Level& level);
};

#endif //GAME_SINGLE_PLAYER_HPP
