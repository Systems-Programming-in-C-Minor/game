
#ifndef GAME_FPS_INDICATOR_HPP
#define GAME_FPS_INDICATOR_HPP

#include <gameobject.hpp>
#include <interfaces/itickable.hpp>
#include "listeners/key_listener.hpp"

class FpsIndicator : public Component, public ITickable, public KeyListener {
public:
	explicit FpsIndicator(EventManager& event_manager)
		: KeyListener(event_manager), _is_visible(false)
	{
	}

private:
	bool _is_visible;

    void tick(GameObject &_game_object) override;
	void on_key_pressed(const KeyPressedEvent& event) override;
};

#endif //GAME_FPS_INDICATOR_HPP
