
#ifndef GAME_GAME_BEHAVIOUR_HPP
#define GAME_GAME_BEHAVIOUR_HPP

#include <listeners/key_listener.hpp>
#include <gameobject.hpp>
#include "listeners/checkpoint_listener.hpp"
#include "race/objects/car.hpp"
#include "listeners/multiplayer_listener.hpp"
#include <optional>

class GameBehaviour
        : public GameObject, protected KeyListener, protected CheckpointListener, protected MultiplayerListener {
public:
    explicit GameBehaviour(EventManager &event_manager, std::vector<std::shared_ptr<Car>> cars,
                           int number_of_laps = 3, int cars_to_finish = 3);

protected:
    void finish();
    void start();

    void on_key_pressed(const KeyPressedEvent &event) override;

    void on_key_released(const KeyReleasedEvent &event) override;

    void on_checkpoint_reached(const CheckpointReachedEvent &event) override;

    void on_checkpoint_lapped(const CheckpointLappedEvent &event) override;

    void on_start_game(const StartGameMultiplayerEvent &event) override;

    void on_stop_game(const StopGameMultiplayerEvent &event) override;

private:
    bool _alt_pressed = false;
    bool _started = false;
    bool _finished = false;
    int _number_of_laps;
    int _cars_to_finish;

    std::map<std::shared_ptr<Car>, int> _cars;
};

#endif //GAME_GAME_BEHAVIOUR_HPP
