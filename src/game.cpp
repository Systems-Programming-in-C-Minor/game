#include "game.hpp"
#include <fmt/core.h>

std::string Game::hello() {
    return fmt::format("{}, {}!", "Hello", "World");
}