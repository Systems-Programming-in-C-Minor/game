#include "levels/level2_factory.hpp"

RaceLevel Level2Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    return RaceLevel{{}, {}, scene};
}
