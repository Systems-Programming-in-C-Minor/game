
#ifndef GAME_COOP_HPP
#define GAME_COOP_HPP

#include <memory>
#include "scene.hpp"
#include "levels/level.hpp"

class CoopMode {
public:
    static std::shared_ptr<Scene> get(const Level& level);
};

#endif //GAME_COOP_HPP
