enable_testing()

include_directories(${CMAKE_SOURCE_DIR}/src)
include_directories(${googletest_SOURCE_DIR}/include ${googletest_BINARY_DIR})

add_executable(test_trafficmonitor test_main.cpp test_TrafficMonitor.cpp)
target_link_libraries(test_trafficmonitor gtest gtest_main trafficmonitorlib)

add_test(NAME test_trafficmonitor COMMAND test_trafficmonitor)