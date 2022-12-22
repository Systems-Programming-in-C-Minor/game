#include "listeners/back_listener.hpp"
#include "scenes/mode_selector_factory.hpp"
#include <global.hpp>

BackListener::BackListener(EventManager &event_manager) : UiObjectListener(event_manager) {}

void BackListener::on_uiobject_released(const UiObjectReleasedEvent &event) {
    if (event.button != BUTTON_LEFT)
        return;

    if (event.ui_object.get_name() == "back") {
        Global::get_instance()->get_engine().load_scene(ModeSelectorFactory::get());
        return;
    }
}

