cmake_minimum_required(VERSION 3.7)
project(DrumMachine)
set(CMAKE_LIBRARY_PATH ${CMAKE_LIBRARY_PATH} /usr/lib/)

set(CMAKE_CXX_STANDARD 14)

#find_package(Boost REQUIRED COMPONENTS thread system)

set(SOURCE_FILES main.cpp DrumMachine.cpp Sample.cpp Timer.cpp)


add_executable(DrumMachine ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} SDL2)
target_link_libraries(${PROJECT_NAME} SDL2_image)
target_link_libraries(${PROJECT_NAME} SDL2_mixer)
#target_link_libraries(${PROJECT_NAME} ${Boost_LIBRARIES})
#target_link_libraries(${PROJECT_NAME} pthread)