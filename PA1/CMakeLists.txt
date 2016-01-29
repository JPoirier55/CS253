cmake_minimum_required(VERSION 3.3)
project(PA1)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(/home/jpoirier/CS253/PA1)

set(SOURCE_FILES main.cpp PoseDisplay.cpp Point3D.h PoseDisplay.h)

add_executable(${SOURCE_FILES} main.cpp)
