//
// Created by Ahmed on 2/22/2025.
//
#include "TrafficMonitor.h"
#include <algorithm>
#include <iostream>

TrafficMonitor::TrafficMonitor(int interval)
  : state(State::INIT), period(interval), errorCounter(0), vehicleCounts(), vehicleList() {
}

void TrafficMonitor::start() {
  if (state == State::INIT) {
    state = State::ACTIVE;
  }
}

void TrafficMonitor::stop() {
  if (state == State::ACTIVE) {
    state = State::STOPPED;
  }
}

void TrafficMonitor::reset() {
  state = State::ACTIVE;
  resetStatistics();
}

void TrafficMonitor::onSignal(const Vehicle &vehicle) {
  if (state == State::ACTIVE) {
    std::string id = vehicle.getId();
    vehicleCounts[id] = vehicleCounts[id] + 1;
    if (std::find(vehicleList.begin(), vehicleList.end(), vehicle) == vehicleList.end()) {
      vehicleList.push_back(vehicle);
    }
  } else if (state == State::ERROR) {
    errorCounter++;
    std::cout << "Error: Vehicle signal received in Error state for vehicle ID: " << vehicle.getId()
        << std::endl;
  }
}

void TrafficMonitor::onSignal() {
  if (state == State::ACTIVE) {
    state = State::ERROR;
  }
}

void TrafficMonitor::onSignalReset() {
  reset();
}

int TrafficMonitor::getErrorCount() const {
  return errorCounter;
}

std::vector<std::string> TrafficMonitor::getStatistics(Vehicle::Type type) const {
  std::vector<std::string> stats;
  for (const auto &vehicle: vehicleList) {
    if (vehicle.getType() == type) {
      stats.push_back(vehicle.getId() + " - (" + std::to_string(vehicleCounts.at(vehicle.getId()))
        + ")");
    }
  }
  std::sort(stats.begin(), stats.end());
  return stats;
}

std::vector<std::string> TrafficMonitor::getStatistics() const {
  std::vector<std::string> stats;
  for (const auto &vehicle: vehicleList) {
    stats.push_back(vehicle.getId() + " - " + std::to_string(vehicleCounts.at(vehicle.getId()))
      + ")");
  }
  std::sort(stats.begin(), stats.end());
  return stats;
}

void TrafficMonitor::resetStatistics() {
  vehicleCounts.clear();
  vehicleList.clear();
  errorCounter = 0;
}

TrafficMonitor::State TrafficMonitor::getState() const {
  return state;
}
