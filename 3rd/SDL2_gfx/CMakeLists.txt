cmake_minimum_required(VERSION 3.12...3.22)

project(
    "SDL2_gfx"
    LANGUAGES "C"
    VERSION "1.0.4"
    DESCRIPTION "SDL2_gfx - Graphics primitives for SDL2"
    HOMEPAGE_URL
        "https://www.ferzkopp.net/wordpress/2016/01/02/sdl_gfx-sdl2_gfx/"
)

add_library(
    "SDL2_gfx"
    "SDL2_framerate.c"
    "SDL2_gfxPrimitives.c"
    "SDL2_imageFilter.c"
    "SDL2_rotozoom.c"
)
target_include_directories("SDL2_gfx" PUBLIC "${PROJECT_SOURCE_DIR}")
target_link_libraries("SDL2_gfx" PUBLIC "SDL2-static")
