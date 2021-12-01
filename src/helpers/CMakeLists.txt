add_library(
    "helpers"
    "math.cpp"
    "random.cpp"
    "Renderer.cpp"
)
target_include_directories("helpers" PUBLIC "${PROJECT_SOURCE_DIR}/inc")
target_link_libraries(
    "helpers"
    PUBLIC "glm"
           "SDL2-static"
           "SDL2_gfx"
)
