
#ifndef GAME_COOP_HPP
#define GAME_COOP_HPP

#include <memory>
#include "scene.hpp"
#include "race/models/level.hpp"

class CoopMode {
public:
    static std::shared_ptr<Scene> get(const RaceLevel& level);
};

#endif //GAME_COOP_HPP
