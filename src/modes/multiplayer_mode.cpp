#include "modes/multiplayer_mode.hpp"
#include "race/behaviours/multiplayer_behaviour.hpp"
#include "listeners/car_audio_listener.hpp"
#include "global.hpp"
#include <camera.hpp>

std::shared_ptr<Scene> MultiplayerMode::get(const RaceLevel &level) {
    Global::get_instance()->get_engine().enable_multiplayer("signaling.maik.sh:10000");

    const auto car_audio_listener = std::make_shared<CarAudioListenerComponent>(level.scene->get_event_manager());

    auto active_car_components = std::list<std::shared_ptr<Component>>{car_audio_listener};

    auto car_sounds = car_audio_listener->get_sounds();
    active_car_components.insert( active_car_components.end(), car_sounds.begin(), car_sounds.end() );

    auto active_car_children = std::list<std::shared_ptr<GameObject>>{level.scene->get_camera()};

    for (int i = 0; i < level.cars.size(); i++) {
        level.cars[i]->add_component(std::make_shared<MultiplayerBehaviour>(
                level.scene->get_event_manager(),
                i,
                level.targets,
                active_car_components,
                active_car_children
        ));
    }

    return level.scene;
}
