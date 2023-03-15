cmake_minimum_required(VERSION 3.24)
project(part_2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(part_2
        Bakery.cpp
        Bakery.h
        w7_p2.cpp)
