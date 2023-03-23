cmake_minimum_required(VERSION 3.24)
project(MS3)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(MS3
        CustomerOrder.cpp
        CustomerOrder.h
        LineManager.cpp
        LineManager.h
        ms3.cpp
        Station.cpp
        Station.h
        Utilities.cpp
        Utilities.h
        Workstation.cpp
        Workstation.h)
