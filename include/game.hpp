#pragma once

#include "engine.hpp"
#include <string>

class Game {
public:
    Engine _engine;

    std::shared_ptr<Scene> _current_scene;

    void start_game();
    void exit_game();
};

