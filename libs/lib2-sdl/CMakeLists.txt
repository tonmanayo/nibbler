cmake_minimum_required(VERSION 3.0.0)
project (SDL)
set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)
INCLUDE(FindPkgConfig)
pkg_check_modules(SDL2 REQUIRED sdl2)
pkg_check_modules(SDL2_TTF REQUIRED SDL2_ttf)
include_directories(${SDL2_INCLUDE_DIRS}
        inc
        ../../inc
        ${SDL2_INCLUDE_DIRS}
        ${SDL2_TTF_INCLUDE_DIRS})
link_directories (${SDL2_LIBRARY_DIRS}
        ${SDL2_TTF_LIBRARY_DIRS})
file(GLOB SOURCES src/*.cpp ../../src/*.cpp)
add_library(SDL MODULE ${SOURCES})
target_link_libraries(SDL
        ${SDL2_LIBRARIES}
        ${SDL2_TTF_LIBRARIES})
