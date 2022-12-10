#include "levels/level1_factory.hpp"

std::shared_ptr<Scene> Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();
    return scene;
}
