#ifndef GAME_LEVEL2_HPP
#define GAME_LEVEL2_HPP

#include <scene.hpp>
#include "level_factory.hpp"

class Level2Factory : public LevelFactory {
public:
    Level get() override;

};

#endif //GAME_LEVEL2_HPP
