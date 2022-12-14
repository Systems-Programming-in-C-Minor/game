#ifndef GAME_LEVEL2_HPP
#define GAME_LEVEL2_HPP

#include <scene.hpp>
#include "level_factory.hpp"

class Level2Factory : public LevelFactory {
public:
    std::shared_ptr<Scene> get() override;

};

#endif //GAME_LEVEL2_HPP
