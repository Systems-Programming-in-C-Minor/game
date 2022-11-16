#include <gtest/gtest.h>
#include "game.hpp"

TEST(EngineTest, ReturnsHelloWorld) {
    EXPECT_EQ(hello(), "Hello, World!");
}