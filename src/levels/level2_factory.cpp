#include "levels/level2_factory.hpp"

#include "components/audiosource.hpp"

RaceLevel Level2Factory::get() {
    std::shared_ptr<Scene> scene = std::make_shared<Scene>(std::shared_ptr<Camera>(), "level 2");

    const auto background_music = std::make_shared<AudioSource>("./assets/audio/background2.mp3", false, false, 0.1, "background");
    background_music->play();
    return RaceLevel{{}, {}, scene};
}
