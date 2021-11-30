add_library("helpers" "math.cpp" "random.cpp")
target_include_directories("helpers" PUBLIC "${PROJECT_SOURCE_DIR}/inc")
