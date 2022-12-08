#include <cstdlib>
#include "game.hpp"

int main(int argc, char **argv){
    Game game;
    game.start_game();
    game.exit_game();
    exit(0);
}

void Game::start_game() {
    const Scene scene;
    std::shared_ptr<Scene> p_scene = std::make_shared<Scene>();
    _current_scene = p_scene;
    _engine.load_scene(_current_scene);
    _engine.start();
}

void Game::exit_game() {
    _engine.stop();
}