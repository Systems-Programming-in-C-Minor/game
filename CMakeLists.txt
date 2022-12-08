cmake_minimum_required(VERSION 3.23)
project(game)

option(GAME_TEST "Generate the test target." ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (CMAKE_VERSION VERSION_GREATER_EQUAL "3.24.0")
    cmake_policy(SET CMP0135 NEW)
endif ()

include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)

FetchContent_Declare(
        engine
        GIT_REPOSITORY git@github.com:Systems-Programming-in-C-Minor/engine.git
        GIT_TAG origin/master
)

FetchContent_MakeAvailable(engine)

add_executable(${PROJECT_NAME} ./src/game.cpp)
target_include_directories(game PUBLIC include)

target_link_libraries(game PRIVATE
        engine
        )

if (GAME_TEST)
    add_subdirectory(test)
    enable_testing()
endif ()
