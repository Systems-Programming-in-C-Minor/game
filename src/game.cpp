#include <cstdlib>
#include "game.hpp"
#include "global.hpp"
#include "gameobject.hpp"
#include "components/sprite.hpp"
#include "levels/levels_factory.hpp"
#include "events.hpp"
#include "modes/singleplayer_mode.hpp"
#include "modes/coop_mode.hpp"

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

//    _current_scene = SingleplayerMode::get(LevelsFactory::get_level1());
    _current_scene = CoopMode::get(LevelsFactory::get_level1());

    engine.load_scene(_current_scene);

    auto moved_event = MouseMovedEvent(1.f, 1.f);
    Global::get_instance()->notify_event_manager(moved_event);

    engine.start();
}

void Game::exit_game() const {
    _global->get_engine().stop();


}