cmake_minimum_required(VERSION 3.0.0)

project (SFML)
set (CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
#Find any version 2.X of SFML
#See the FindSFML.cmake file for additional details and instructions
find_package(SFML REQUIRED network audio graphics window system)

if(SFML_FOUND)
    include_directories(inc ../../inc ${SFML_INCLUDE_DIR})
    file(GLOB SOURCES src/*.cpp ../../src/*.cpp)
    link_directories(inc ../../inc ${SFML_INCLUDE_DIR} ~/.brew/Cellar/sfml/2.4.2/lib/ )
    add_library(SFML MODULE ${SOURCES})
    target_link_libraries(SFML ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

#set(SFML_INCLUDE_DIR ~/.brew/include/)
