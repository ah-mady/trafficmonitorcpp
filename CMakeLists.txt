cmake_minimum_required(VERSION 3.30)
project(transmogrification)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(transmogrification src/main.cpp src/TrafficMonitor.cpp
)
add_subdirectory(src)
add_subdirectory(tests)