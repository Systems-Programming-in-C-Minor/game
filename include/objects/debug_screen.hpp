
#ifndef GAME_DEBUG_SCREEN_HPP
#define GAME_DEBUG_SCREEN_HPP

#include <gameobject.hpp>
#include <listeners/mouse_listener.hpp>

class DebugScreenToWorld : public GameObject, public MouseListener {
public:
    DebugScreenToWorld(EventManager &event_manager);

    void on_mouse_pressed(const MousePressedEvent &event) override;
};


#endif //GAME_DEBUG_SCREEN_HPP
