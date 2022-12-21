
#ifndef GAME_DRAG_COLLIDER_HPP
#define GAME_DRAG_COLLIDER_HPP

#include <optional>
#include "gameobject.hpp"
#include "string"
#include "events.hpp"
#include "listeners/collider_listener.hpp"

class Car;

class DragCollider : public GameObject, public ColliderListener {
public:
    DragCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                 float drag_modifier, const std::pair<std::string, std::string> &drag_collider_paths = {});

    void on_collider_entry(const ColliderEntryEvent &event) override;

    void on_collider_exit(const ColliderExitEvent &event) override;

private:
    class DragObject {
    public:
        bool _collided_outer = false;
        bool _collided_inner = false;
        bool _drag_applied = false;
    };

    void toggle_drag_on_car(RigidBody *body, Car *car, bool collider_entry);

    void apply_drag(Car *car, const std::shared_ptr<DragObject> &drag) const;

    void remove_drag(Car *car, const std::shared_ptr<DragObject> &drag) const;

    RigidBody *_outer_body;
    RigidBody *_inner_body;

    std::map<Car *, std::shared_ptr<DragObject>> _car_drags;

    const float _drag_modifier;

    std::vector<Car *> applied_on;
};

#endif //GAME_DRAG_COLLIDER_HPP
