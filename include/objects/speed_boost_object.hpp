
#ifndef GAME_SPEED_BOOST_OBJECT_HPP
#define GAME_SPEED_BOOST_OBJECT_HPP

#include <gameobject.hpp>
#include <listeners/collider_listener.hpp>
#include <race/objects/car.hpp>

class SpeedBoostObject : public GameObject, public ColliderListener {
public:
    SpeedBoostObject(EventManager &event_manager, const std::shared_ptr<Scene> &scene, Vector2d position,
                     float angle, int tick_duration);

    void on_collider_entry(const ColliderEntryEvent &event) override;

    void tick() override;

private:
    const int _tick_duration;
    std::map<Car *, int> _car_boosts;
};

#endif //GAME_SPEED_BOOST_OBJECT_HPP
