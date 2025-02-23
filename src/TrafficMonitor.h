//
// Created by Ahmed on 2/22/2025.
//

#ifndef TRAFFICMONITOR_H
#define TRAFFICMONITOR_H

#include "Vehicle.h"
#include <map>
#include <vector>
#include <string>

class TrafficMonitor {
  public:
    enum class State { INIT, ACTIVE, ERROR, STOPPED };

    explicit TrafficMonitor(int period);
    void start();
    void stop();
    void reset();
    void onSignal(const Vehicle &vehicle);
    void onSignal();
    void onSignalReset();
    int getErrorCount() const;
    std::vector<std::string> getStatistics(Vehicle::Type type) const;
    std::vector<std::string> getStatistics() const;
    State getState() const;

  private:
    void resetStatistics();

    State state;
    int period;
    int errorCounter;
    std::map<std::string, int> vehicleCounts;
    std::vector<Vehicle> vehicleList;
};

#endif // TRAFFICMONITOR_H
