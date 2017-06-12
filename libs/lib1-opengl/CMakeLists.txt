
cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_BUILD_TYPE Release)
set (CMAKE_CXX_STANDARD 11)

project (OpenGL)
find_package(PkgConfig)
pkg_check_modules(Allegro5_PKGCONF allegro-5)

MESSAGE("lib: ${Allegro5_PKGCONF_LIBRARY_DIRS}")
MESSAGE("include: ${Allegro5_PKGCONF_INCLUDE_DIRS}")
pkg_search_module(ALLEGRO5 REQUIRED allegro-5 allegro-5.2)

find_path(Allegro5_INCLUDE_DIR
        NAMES allegro5/allegro5.h
        PATHS ${Allegro5_PKGCONF_INCLUDE_DIRS})

message("include dir: ${Allegro5_INCLUDE_DIR}")

set(ALLEGRO5_ALL_LIBRARIES
        allegro allegro_image allegro_font
        allegro_primitives allegro_ttf allegro_audio
        allegro_dialog allegro_memfile allegro_acodec
        allegro_color allegro_main allegro_physfs)

foreach(ALLEGRO5_ONE_LIBRARY ${ALLEGRO5_ALL_LIBRARIES})
    #message("${ALLEGRO5_ONE_LIBRARY}")
    find_library("${ALLEGRO5_ONE_LIBRARY}_AID" "${ALLEGRO5_ONE_LIBRARY}"
            ${Allegro5_PKGCONF_LIBRARY_DIRS})
    set(Allegro5_LIBRARIES
            "${Allegro5_LIBRARIES}" "${${ALLEGRO5_ONE_LIBRARY}_AID}")
    #MESSAGE("${Allegro5_LIBRARIES}")
endforeach(ALLEGRO5_ONE_LIBRARY)

#MESSAGE("${Allegro5_LIBRARIES}")
#message("${ALLEGRO5_LIBRARIES}")

set(ALLEGRO_INCLUDE_DIR "${Allegro5_INCLUDE_DIR}")
set(ALLEGRO_LIBRARIES "${Allegro5_LIBRARIES}")

#libfind_process(Allegro5)

 MESSAGE("all libs: ${ALLEGRO_LIBRARIES}")
 MESSAGE("all include: ${ALLEGRO_INCLUDE_DIR}")

FIND_PACKAGE_HANDLE_STANDARD_ARGS(Allegro5 DEFAULT_MSG ALLEGRO_LIBRARIES ALLEGRO_INCLUDE_DIR)


include_directories(inc ../../inc ${ALLEGRO_INCLUDE_DIR})
link_directories(inc ../../inc ${ALLEGRO_INCLUDE_DIR})
file(GLOB SOURCES src/*.cpp ../../src/*.cpp)
add_library(OpenGL MODULE ${SOURCES})
target_link_libraries(OpenGL ${ALLEGRO_LIBRARIES})
