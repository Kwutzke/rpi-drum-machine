cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES
        main.cpp
        RaspOutputController.h
        RaspOutputController.cpp
        RaspInputController.h
        RaspInputController.cpp
        DrumMachine.h
        DrumMachine.cpp
        DrumMachineInputListener.h
        DrumMachineInputListener.cpp
        Sample.h
        Sample.cpp
        Timer.h
        Timer.cpp
        AOutputController.h
        InputListener.h
        Display.h
        Display.cpp
        )

add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} wiringPi)
target_link_libraries(${PROJECT_NAME} ssd1306)