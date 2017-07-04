cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)

add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(DrumMachine SDL2)
target_link_libraries(DrumMachine SDL2_image)
target_link_libraries(DrumMachine SDL2_mixer)