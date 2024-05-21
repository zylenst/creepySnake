cmake_minimum_required(VERSION 3.29.3)

project(CreepySnake)

set(CMAKE_CXX_STANDARD 17)

# Include vcpkg toolchain file
# set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

# Find SFML package
find_package(SFML 2.5 COMPONENTS system window graphics REQUIRED)

# Add include directories
include_directories(${SFML_INCLUDE_DIRS})

# Add the executable
add_executable(CreepySnake src/main.cpp include/game.h)

# Link SFML libraries
target_link_libraries(CreepySnake sfml-system sfml-window sfml-graphics)

