enable_testing()

add_executable(test_trafficmonitor test_main.cpp test_TrafficMonitor.cpp)
target_link_libraries(test_trafficmonitor gtest gtest_main)

add_test(NAME test_trafficmonitor COMMAND test_trafficmonitor)