cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 14)

set(PROJECT_NAME template)
project(${PROJECT_NAME})

file(GLOB_RECURSE main_sources src/*.cpp)
add_executable(${PROJECT_NAME} ${main_sources})

find_package(SFML COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio sfml-network)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} glu32 opengl32)