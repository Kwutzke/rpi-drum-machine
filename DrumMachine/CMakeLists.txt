cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

<<<<<<< HEAD
set(SOURCE_FILES main.cpp DrumMachine.cpp Sample.cpp Timer.cpp)
#set(SOURCE_FILES LedController.cpp)
=======
#find_package(Boost REQUIRED COMPONENTS thread system)

set(SOURCE_FILES main.cpp DrumMachine.cpp Sample.cpp Timer.cpp)
>>>>>>> 8e0117eb11622486af81d3a9ff23bf6b6c04c08c


add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
target_link_libraries(${PROJECT_NAME} pthread)
<<<<<<< HEAD
#target_link_libraries(${PROJECT_NAME} wiringPi)
=======
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} pthread)
>>>>>>> 8e0117eb11622486af81d3a9ff23bf6b6c04c08c
