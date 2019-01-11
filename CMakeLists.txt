cmake_minimum_required(VERSION 3.13)
project(minesweeper)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -IC:/dev/libs/sfml/include -LC:/dev/libs/sfml/lib")
set(SOURCE_FILES main.cpp )
set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules)
find_package(SFML REQUIRED COMPONENTS audio network graphics window system)

include_directories(${SFML_INCLUDE_DIR})
add_executable(minesweeper main.cpp tilemap.cpp tilemap.h inputhandler.cpp inputhandler.h mouseclick.cpp mouseclick.h)
target_link_libraries(minesweeper sfml-audio sfml-network sfml-graphics sfml-window sfml-system)