cmake_minimum_required(VERSION 3.10)
project(dungeon)

set(CMAKE_CXX_STANDARD 17)

add_executable(dungeon
    src/main.cpp
)

target_include_directories(dungeon PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)