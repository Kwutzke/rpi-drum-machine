cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        DrumMachine.h
        DrumMachine.cpp
        Sample.h
        Sample.cpp
        Timer.h
        Timer.cpp
        )

add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
target_link_libraries(${PROJECT_NAME} pthread)

