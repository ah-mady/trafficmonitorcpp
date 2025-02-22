cmake_minimum_required(VERSION 3.30)
project(trafficmonitorcpp)

set(CMAKE_CXX_STANDARD 20)

add_executable(trafficmonitorcpp src/main.cpp
        src/Vehicle.h
        src/TrafficMonitor.h
        src/TrafficMonitor.cpp
        tests/test_main.cpp
        tests/test_TrafficMonitor.cpp)
