#include <cstdlib>
#include "game.hpp"
#include "global.hpp"
#include "components/sprite.hpp"
#include "scenes/mode_selector_factory.hpp"
#include "modes/coop_mode.hpp"
#include "levels/level1_factory.hpp"

int main() {
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

//    _current_scene = ModeSelectorFactory::get();
    _current_scene = CoopMode::get(Level1Factory::get());

    engine.load_scene(_current_scene);
    engine.start();
}

void Game::exit_game() const {
    _global->get_engine().stop();
}