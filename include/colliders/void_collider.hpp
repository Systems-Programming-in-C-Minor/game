
#ifndef GAME_VOID_COLLIDER_HPP
#define GAME_VOID_COLLIDER_HPP

#include <optional>
#include "gameobject.hpp"
#include "string"
#include "events.hpp"
#include "listeners/collider_listener.hpp"

class Car;

class VoidCollider : public GameObject, public ColliderListener {
public:
    VoidCollider(const std::string &name, const std::shared_ptr<Scene> &scene, EventManager &event_manager,
                 const std::pair<std::string, std::string> &drag_collider_paths = {});

    void on_collider_entry(const ColliderEntryEvent &event) override;

    void on_collider_exit(const ColliderExitEvent &event) override;

private:
    class VoidObject {
    public:
        explicit VoidObject(float scale);

        const float scale;
        bool collided_outer = false;
        bool collided_inner = false;
        int enter_void = -1;
    };

    static void spawn_back(Car *car);

    void toggle_collided(RigidBody *body, Car *car, bool collider_entry);

    void tick() override;

    const int tick_duration = 200;

    std::map<Car *, std::shared_ptr<VoidObject>> _car_voids;

    RigidBody *_outer_body;
    RigidBody *_inner_body;
};

#endif //GAME_VOID_COLLIDER_HPP
