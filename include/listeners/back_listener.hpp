
#ifndef GAME_BACK_LISTENER_HPP
#define GAME_BACK_LISTENER_HPP

#include <components/component.hpp>
#include <listeners/uiobject_listener.hpp>

class BackListener : public Component, public UiObjectListener {
public:
    explicit BackListener(EventManager &event_manager);

    void on_uiobject_released(const UiObjectReleasedEvent &event) override;
};

#endif //GAME_BACK_LISTENER_HPP
