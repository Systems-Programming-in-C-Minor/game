#include "objects/debug_screen.hpp"
#include <global.hpp>
#include <iostream>

DebugScreenToWorld::DebugScreenToWorld(EventManager &event_manager) : GameObject("debug-screen", "debug"),
                                                                      MouseListener(event_manager) {}

void DebugScreenToWorld::on_mouse_pressed(const MousePressedEvent &event) {
    const auto click_pos = Vector2d{
            static_cast<float>(event.x),
            static_cast<float>(event.y)
    };
    const auto result_pos = Global::get_instance()->get_engine().get_renderer()->screen_to_world_space(click_pos);
    std::cout << result_pos << "\n";
}