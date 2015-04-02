project(SDLTest)
cmake_minimum_required(VERSION 2.8)

# Point to our own cmake modules
list(APPEND CMAKE_MODULE_PATH ${CMAKE_SOURCE_DIR}/CMakeModules)

# Find SDL2
find_package(SDL2 REQUIRED)

# Add global definitions
add_definitions("-Wall")
add_definitions("-std=c++11")
add_definitions("-g")

include_directories(${SDL2_INCLUDE_DIR})
include_directories(src)

set(HEADER_FILES src/Game.h
			src/Logger.h)
			
set(SOURCES src/Game.cpp
			src/Logger.cpp)

add_executable(sdltest main.cpp ${HEADER_FILES} ${SOURCES})
install(TARGETS sdltest DESTINATION bin)
target_link_libraries(sdltest ${SDL2_LIBRARIES})
