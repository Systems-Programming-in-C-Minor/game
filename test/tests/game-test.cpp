#include <gtest/gtest.h>
#include "game.hpp"

TEST(GameTest, ReturnsHelloWorld) {
    Game game {};
    EXPECT_EQ(game.hello(), "Hello, World!");
}