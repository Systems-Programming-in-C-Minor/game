#include "listeners/car_audio_listener.hpp"
#include <components/audiosource.hpp>
#include <components/component.hpp>
#include <gameobject.hpp>
#include <vector>
#include <algorithm>
#include <global.hpp>
#include <iostream>

#include "race/objects/checkpoint.hpp"

CarAudioListenerComponent::CarAudioListenerComponent(EventManager &event_manager) : ColliderListener(event_manager)
{
    const auto sound_accelerate = std::make_shared<AudioSource>("./assets/audio/engine-driving.mp3", false, false, 0.15f, "accelerate");
    const auto sound_engine_idle = std::make_shared<AudioSource>("./assets/audio/engine-idle.mp3", false, false, 0.5f, "engine_idle");
    const auto sound_car_drift = std::make_shared<AudioSource>("./assets/audio/car-drift.mp3", false, false, 0.3f, "car_drift");
    const auto sound_car_leave_screech = std::make_shared<AudioSource>("./assets/audio/car-leave-screech.mp3", false, false, 0.5f, "car_leave");
    const auto sound_car_crash = std::make_shared<AudioSource>("./assets/audio/car-crash.mp3", false, false, 0.3f, "car_crash");

    _sounds.push_back(sound_accelerate);
    _sounds.push_back(sound_engine_idle);
    _sounds.push_back(sound_car_drift);
    _sounds.push_back(sound_car_leave_screech);
    _sounds.push_back(sound_car_crash);
}

void CarAudioListenerComponent::on_collider_entry(const ColliderEntryEvent& event)
{
    if (event.collider_a->game_object != this->game_object && event.collider_b->game_object != this->game_object)
        return;
    if (event.collider_a->game_object->get_tag() == "drag-collider" || event.collider_b->game_object->get_tag() == "drag-collider")
        return;
    if (event.collider_a->game_object->get_tag() == "checkpoint" || event.collider_b->game_object->get_tag() == "checkpoint")
        return;
    if (event.collider_a->game_object->get_tag() == "speed-boost" || event.collider_b->game_object->get_tag() == "speed-boost")
        return;
    if (event.collider_a->game_object->get_tag() == "void-collider" || event.collider_b->game_object->get_tag() == "void-collider")
        return;
    if (event.collider_a->game_object->get_tag() == "ui-debug" || event.collider_b->game_object->get_tag() == "ui-debug")
        return;

    const auto sources = game_object->get_components<AudioSource>();
    for (const auto &sound : sources) {
        if (sound->get_name() == "car_crash") {
            if (!sound->is_playing())
                sound->play();
        }
    }
}

void CarAudioListenerComponent::tick(GameObject &no)
{
    const auto sources = game_object->get_components<AudioSource>();
    const float lateral_velocity = game_object->get_component<RigidBody>()->get_lateral_velocity().length();
    const auto speed = game_object->get_component<RigidBody>()->get_current_speed();
    bool is_moving = false;

    if (speed > 3) {
        is_moving = true;
    }

    for (const auto &sound : sources) {
        if (sound->get_name() == "car_drift") {
            if (lateral_velocity > 6) {
                if (!sound->is_playing())
                    sound->play();
            }
            else {
                sound->stop();
            }
        }
    }
    
    if (is_moving) {
        for (const auto &sound : sources) {
            if (sound->get_name() == "accelerate" && !sound->is_playing()) {
                sound->play();
            }
            if (sound->get_name() == "engine_idle") {
                sound->stop();
            }
        }
    } else {
        for (const auto &sound : sources) {
            if (sound->get_name() == "accelerate") {
                sound->stop();
            }
            if (sound->get_name() == "engine_idle" && !sound->is_playing()) {
                sound->play();
            }
        }
    }
}

std::vector<std::shared_ptr<AudioSource>> CarAudioListenerComponent::get_sounds()
{
    return _sounds;
}
