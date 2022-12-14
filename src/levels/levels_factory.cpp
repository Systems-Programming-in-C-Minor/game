#include "levels/levels_factory.hpp"
#include "levels/level1_factory.hpp"
#include "levels/level2_factory.hpp"

std::shared_ptr<Scene>  LevelsFactory::get_level1() {
    Level1Factory factory {};
    return factory.get();
}

std::shared_ptr<Scene>  LevelsFactory::get_level2() {
    Level2Factory factory {};
    return factory.get();
}
