#ifndef CAR_AUDIO_LISTENER_HPP
#define CAR_AUDIO_LISTENER_HPP
#include <components/component.hpp>
#include <interfaces/itickable.hpp>
#include <listeners/collider_listener.hpp>
#include <components/audiosource.hpp>
#include <vector>
#include <memory>

class CarAudioListenerComponent : public Component, public ITickable, public ColliderListener
{
	std::vector<std::shared_ptr<AudioSource>> _sounds;

public:
	CarAudioListenerComponent(EventManager &event_manager);
	void tick(GameObject& game_object) override;

	void on_collider_entry(const ColliderEntryEvent& event) override;

	[[nodiscard]] std::vector<std::shared_ptr<AudioSource>> get_sounds();
	
};

#endif // !CAR_AUDIO_LISTENER_HPP
