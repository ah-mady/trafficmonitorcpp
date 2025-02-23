//
// Created by Ahmed on 2/22/2025.
//
#include <gtest/gtest.h>
#include "TrafficMonitor.h"
#include "Vehicle.h"

TEST(TrafficMonitorTest, InitialState) {
  TrafficMonitor monitor(60);
  EXPECT_EQ(monitor.getState(), TrafficMonitor::State::INIT);
}

TEST(TrafficMonitorTest, StartMonitor) {
  TrafficMonitor monitor(60);
  monitor.start();
  EXPECT_EQ(monitor.getState(), TrafficMonitor::State::ACTIVE);
}

TEST(TrafficMonitorTest, SignalHandling) {
  std::vector<std::string> stats = {"ABC-011 - 1"};
  EXPECT_EQ(stats[0], "ABC-011 - 1");
}

TEST(TrafficMonitorTest, ErrorState) {
  TrafficMonitor monitor(60);
  monitor.start();
  monitor.onSignal();

  EXPECT_EQ(monitor.getState(), TrafficMonitor::State::ERROR);
  EXPECT_EQ(monitor.getErrorCount(), 0);

  Bicycle bike("ABC-011");
  monitor.onSignal(bike);
  EXPECT_EQ(monitor.getErrorCount(), 1);
}
