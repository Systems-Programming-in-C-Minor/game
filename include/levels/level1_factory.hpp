#ifndef GAME_LEVEL1_HPP
#define GAME_LEVEL1_HPP

#include <scene.hpp>
#include "level_factory.hpp"

class Level1Factory : public LevelFactory {
public:
    Level get() override;

};

#endif //GAME_LEVEL1_HPP
