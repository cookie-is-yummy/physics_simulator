cmake_minimum_required(VERSION 3.0)
project(physics_sim)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

# Fetch raylib
FetchContent_Declare(
        raylib
        GIT_REPOSITORY "https://github.com/raysan5/raylib.git"
        GIT_TAG "master"
)

# Make raylib available
FetchContent_MakeAvailable(raylib)

# Include source files
file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp")

# Create the executable target
add_executable(${PROJECT_NAME} ${PROJECT_SOURCES} src/objects.cpp src/objects.h)

# Link raylib to the target
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)

# Set the assets path (if needed)
target_compile_definitions(${PROJECT_NAME} PUBLIC ASSETS_PATH="${CMAKE_CURRENT_SOURCE_DIR}/assets/")