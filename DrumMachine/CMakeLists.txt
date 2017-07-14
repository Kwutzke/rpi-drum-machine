cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
<<<<<<< HEAD
set(SOURCE_FILES main.cpp DrumMachine.cpp Sample.cpp Timer.cpp AInputController.h RaspInputController.cpp RaspInputController.h)

set(SOURCE_FILES
        main.cpp
        DrumMachine.h
        DrumMachine.cpp
        Sample.h
        Sample.cpp
        Timer.h
        Timer.cpp
        AOutputController.h
        RaspInputController.h
        RaspInputController.cpp
        InputListener.h
        DrumMachineInputListener.h
        DrumMachineInputListener.cpp
        LedController.h
        )
=======
=======
>>>>>>> parent of a6efbd8... bugfixed
set(SOURCE_FILES main.cpp DrumMachine.cpp Sample.cpp Timer.cpp LedController.cpp AOutputController.h AInputController.h RaspInputController.cpp RaspInputController.h)
#set(SOURCE_FILES LedController.cpp)
>>>>>>> parent of a6efbd8... bugfixed


add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
target_link_libraries(${PROJECT_NAME} pthread)
target_link_libraries(${PROJECT_NAME} wiringPi)
