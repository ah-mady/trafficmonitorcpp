#include "TrafficMonitor.h"
#include <iostream>

int main() {
  TrafficMonitor monitor(60);
  monitor.start();

  Bicycle bike1("ABC-011");
  Bicycle bike2("ABC-014");
  Bicycle bike3("ABC-015");
  Car car1("ABC-012");
  Car car2("ABC-013");
  Car car3("ABC-014");
  Scooter scooter1("ABC-013");
  Scooter scooter2("ABC-014");

  monitor.onSignal(bike1);
  monitor.onSignal(bike2);
  monitor.onSignal(bike3);
  monitor.onSignal(car1);
  monitor.onSignal(car2);
  monitor.onSignal(car3);
  monitor.onSignal(scooter1);
  monitor.onSignal(scooter2);

  monitor.onSignal(bike1);
  monitor.onSignal(bike2);
  monitor.onSignal(bike3);
  monitor.onSignal(car1);
  monitor.onSignal(car2);
  monitor.onSignal(scooter1);
  monitor.onSignal(scooter2);
  monitor.onSignal(scooter2);

  std::cout << "Statistics (all):" << std::endl;
  for (const auto &stat: monitor.getStatistics()) {
    std::cout << stat << std::endl;
  }

  std::cout << "\nStatistics (BICYCLE):" << std::endl;
  for (const auto &stat: monitor.getStatistics(Vehicle::Type::BICYCLE)) {
    std::cout << stat << std::endl;
  }

  std::cout << "\nStatistics (CAR):" << std::endl;
  for (const auto &stat: monitor.getStatistics(Vehicle::Type::CAR)) {
    std::cout << stat << std::endl;
  }

  std::cout << "\nStatistics (SCOOTER):" << std::endl;
  for (const auto &stat: monitor.getStatistics(Vehicle::Type::SCOOTER)) {
    std::cout << stat << std::endl;
  }

  std::cout << "\nError count: " << monitor.getErrorCount() << std::endl;

  monitor.onSignal();
  std::cout << "\nState after error signal: " << static_cast<int>(monitor.getState()) << std::endl;

  monitor.onSignal(bike1);
  std::cout << "Error count after vehicle signal in ERROR state: " << monitor.getErrorCount() <<
      std::endl;

  monitor.onSignalReset();
  std::cout << "\nState after reset signal: " << static_cast<int>(monitor.getState()) << std::endl;

  std::cout << "\nStatistics after reset (all):" << std::endl;
  for (const auto &stat: monitor.getStatistics()) {
    std::cout << stat << std::endl;
  }

  std::cout << "\nError count after reset: " << monitor.getErrorCount() << std::endl;

  return 0;
}
