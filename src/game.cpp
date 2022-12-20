#include <cstdlib>
#include "game.hpp"
#include "global.hpp"
#include "components/sprite.hpp"
#include "levels/levels_factory.hpp"
#include "events.hpp"
#include <global.hpp>
#include "modes/singleplayer_mode.hpp"
#include "modes/coop_mode.hpp"
#include "modes/controller_mode.hpp"

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

    // TODO implement switch scene between modes
    if (Global::get_instance()->get_engine().get_number_of_controllers() > 0)
        _current_scene = ControllerMode::get(LevelsFactory::get_level1());
    else
        _current_scene = CoopMode::get(LevelsFactory::get_level1());
//     _current_scene = SingleplayerMode::get(LevelsFactory::get_level1());

    engine.load_scene(_current_scene);
    engine.start();
}

void Game::exit_game() const {
    _global->get_engine().stop();


}