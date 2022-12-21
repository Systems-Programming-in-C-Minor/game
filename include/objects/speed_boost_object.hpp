
#ifndef GAME_SPEED_BOOST_OBJECT_HPP
#define GAME_SPEED_BOOST_OBJECT_HPP

#include <gameobject.hpp>
#include <listeners/collider_listener.hpp>
#include <race/objects/car.hpp>

class SpeedBoostObject : public GameObject, public ColliderListener {
public:
    SpeedBoostObject(EventManager &event_manager, const std::shared_ptr<Scene> &scene, Vector2d position,
                     float angle, int tick_duration = 300, float boost_force = 400.f, float boost_speed = 1000.f);

    void on_collider_entry(const ColliderEntryEvent &event) override;

    void on_collider_exit(const ColliderExitEvent &event) override;

    void tick() override;

private:
    const float _boost_force;
    const float _boost_speed;
    const int _tick_duration;

    int _cars_on_booster = 0;

    std::map<Car *, int> _car_boosts;

    void set_boost(Car *car);

    void apply_boost(Car *car) const;

    void remove_boost(Car *car) const;
};

#endif //GAME_SPEED_BOOST_OBJECT_HPP
