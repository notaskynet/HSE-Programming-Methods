cmake_minimum_required(VERSION 3.10)
project(sort_ships)

set(CMAKE_CXX_STANDARD 17)

add_executable(sort_ships 
    src/main.cpp 
    src/ship.cpp 
    src/sorts.cpp
)

target_include_directories(sort_ships PRIVATE ${CMAKE_SOURCE_DIR})