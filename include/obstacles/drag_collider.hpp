
#ifndef GAME_DRAG_COLLIDER_HPP
#define GAME_DRAG_COLLIDER_HPP

#include <optional>
#include "gameobject.hpp"
#include "string"
#include "events.hpp"
#include "listeners/collider_listener.hpp"

class DragCollider : public GameObject, public ColliderListener {
public:
    DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene, float drag_modifier, const std::vector<std::string>& drag_collider_paths = {});

    void on_collider_entry(const ColliderEntryEvent &event) override;

    void on_collider_exit(const ColliderExitEvent &event) override;

private:
    void check_for_car(GameObject *game_object, bool enter_collider) const;

    const float _drag_modifier;
};

#endif //GAME_DRAG_COLLIDER_HPP
