#include <cstdlib>
#include "game.hpp"
#include "global.hpp"
#include "color.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "global.hpp"
#include "scene.hpp"
#include "interfaces/itickable.hpp"

int main(){
    Game game;
    game.start_game();

    game.exit_game();
    exit(0);
}

void Game::start_game() {
    _global = Global::get_instance();
    auto p_engine = std::make_unique<Engine>();
    _global->set_engine(std::move(p_engine));
    Engine &engine = _global->get_engine();

    const Scene scene;
    std::shared_ptr<Scene> p_scene = std::make_shared<Scene>();
    _current_scene = p_scene;

    engine.load_scene(_current_scene);
    engine.start();
}

void Game::exit_game() {
    _global->get_engine().stop();

    
}