cmake_minimum_required(VERSION 3.24)
project(MS2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS2
        CustomerOrder.cpp
        CustomerOrder.h
        ms2.cpp
        Station.cpp
        Station.h
        Utilities.cpp
        Utilities.h)
