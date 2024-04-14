cmake_minimum_required(VERSION 3.27)
project(Chess C)

set(CMAKE_C_STANDARD 11)

# Adding Raylib
include(FetchContent)
set(FETCHCONTENT_QUIET FALSE)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games

FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
        GIT_PROGRESS TRUE
)

FetchContent_MakeAvailable(raylib)

include_directories(src/include)

add_executable(
    Chess
    src/main.c
    src/include/input.h
    src/input.c
    src/include/board.h
    src/board.c
    src/include/pieces.h
    src/pieces.c
    src/include/game.h
    src/game.c
    src/include/input.h
    src/input.c
)
target_link_libraries(Chess raylib)