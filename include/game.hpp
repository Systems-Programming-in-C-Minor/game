#pragma once

#include "engine.hpp"
#include "scene.hpp"
#include <string>

class Game {
public:
    Engine _engine;

    Scene _current_scene;

    void start_game();
};

