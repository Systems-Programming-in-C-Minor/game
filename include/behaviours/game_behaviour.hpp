
#ifndef GAME_GAME_BEHAVIOUR_HPP
#define GAME_GAME_BEHAVIOUR_HPP

#include <listeners/key_listener.hpp>
#include <gameobject.hpp>
#include "listeners/checkpoint_listener.hpp"
#include "race/objects/car.hpp"
#include <optional>

class GameBehaviour : public GameObject, public KeyListener, public CheckpointListener {
public:
    explicit GameBehaviour(EventManager &event_manager, std::vector<std::shared_ptr<Car>> cars,
                           int number_of_laps = 3, int cars_to_finish = 3);

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

    void on_checkpoint_reached(const CheckpointReachedEvent &event) override;

    void on_checkpoint_lapped(const CheckpointLappedEvent &event) override;

    void finish();

private:
    bool _alt_pressed = false;
    bool _started = false;
    bool _finished = false;
    int _number_of_laps;
    int _cars_to_finish;

    std::map<std::shared_ptr<Car>, int> _cars;
};

#endif //GAME_GAME_BEHAVIOUR_HPP
