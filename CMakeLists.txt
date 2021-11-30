cmake_minimum_required(VERSION 3.12...3.22)

project(
    "CodingTrain.cpp"
    LANGUAGES "CXX"
    VERSION "0.1.0"
    DESCRIPTION "The Coding Train, in C++"
    HOMEPAGE_URL "https://github.com/Phytolizer/CodingTrain.cpp"
)

include(FetchContent)
FetchContent_Declare(
    "SDL"
    GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
    GIT_TAG "release-2.0.16"
)
option(SDL_SHARED OFF)
FetchContent_MakeAvailable("SDL")
FetchContent_Declare(
    "glm"
    GIT_REPOSITORY "https://github.com/g-truc/glm.git"
    GIT_TAG "0.9.9.8"
)
FetchContent_MakeAvailable("glm")

add_subdirectory("3rd/SDL2_gfx")
add_subdirectory("src/helpers")
add_subdirectory("src/challenges")
