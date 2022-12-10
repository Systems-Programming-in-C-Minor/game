
#ifndef GAME_LEVEL_FACTORY_HPP
#define GAME_LEVEL_FACTORY_HPP

#include <scene.hpp>

class LevelFactory {
public:
    virtual std::shared_ptr<Scene> get() = 0;

};

#endif //GAME_LEVEL_FACTORY_HPP
