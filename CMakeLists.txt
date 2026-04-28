cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(myapp
    src/main.cpp
)

target_include_directories(myapp PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)
