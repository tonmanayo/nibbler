
cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)


find_package(PkgConfig)
pkg_check_modules(ALLEGRO REQUIRED allegro-5)
pkg_check_modules(ALLEGRO_PRIMITIVES REQUIRED allegro_primitives-5)
pkg_check_modules(ALLEGRO_MAIN REQUIRED allegro_main-5)
pkg_check_modules(ALLEGRO_TTF REQUIRED allegro_ttf-5)
pkg_check_modules(ALLEGRO_FONT REQUIRED allegro_font-5)

include_directories(inc ../../inc  ${ALLEGRO_INCLUDE_DIRS} ${ALLEGRO_PRIMITIVES_INCLUDE_DIRS} ${ALLEGRO_MAIN_INCLUDE_DIRS} ${ALLEGRO_FONT_INCLUDE_DIRS} ${ALLEGRO_TTF_INCLUDE_DIRS})
link_directories(inc ../../inc ~/.brew/Cellar/allegro/5.2.2/lib/ ${ALLEGRO_LIBRARY_DIRS}  ${ALLEGRO_PRIMITIVES_LIBRARY_DIRS} ${ALLEGRO_MAIN_LIBRARY_DIRS} ${ALLEGRO_FONT_LIBRARY_DIRS} ${ALLEGRO_TTF_LIBRARY_DIRS})



#include_directories(inc ../../inc ${ALLEGRO_INCLUDE_DIR})
#link_directories(inc ../../inc ${ALLEGRO_INCLUDE_DIR})
file(GLOB SOURCES src/*.cpp ../../src/*.cpp)
add_library(OpenGL MODULE ${SOURCES})
#target_link_libraries(OpenGL ${ALLEGRO_LIBRARIES})
target_link_libraries(OpenGL ${ALLEGRO_LIBRARIES} ${ALLEGRO_PRIMITIVES_LIBRARIES} ${ALLEGRO_FONT_LIBRARIES} ${ALLEGRO_TTF_LIBRARIES} ${MATH_LIB})
