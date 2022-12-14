#include "levels/level2_factory.hpp"

std::shared_ptr<Scene> Level2Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    return scene;
}
