#pragma once
#include <string>
#include "scene.hpp"

class Global;

class Game {
public:
    Global *_global;

    std::shared_ptr<Scene> _current_scene;

    void start_game();
    void exit_game();
};

