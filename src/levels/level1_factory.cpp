#include "levels/level1_factory.hpp"
#include "track_factory.hpp"

std::shared_ptr<Scene> Level1Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>();

    const auto track = TrackFactory::get("level1-track", "level1", "../assets/tracks/track1.png");
    scene->gameobjects.push_back(track);

    return scene;
}
