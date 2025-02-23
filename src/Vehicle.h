//
// Created by Ahmed on 2/22/2025.
//

#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>

class Vehicle {
  public:
    enum class Type { BICYCLE, CAR, SCOOTER };

    Vehicle(const std::string &id, Type type) : id(id), type(type) {
    }
    bool operator==(const Vehicle &other) const {
      return id == other.id && type == other.type;
    }
    virtual ~Vehicle() = default;

    std::string getId() const { return id; }
    Type getType() const { return type; }

  private:
    std::string id;
    Type type;
};

class Bicycle: public Vehicle {
  public:
    Bicycle(const std::string &id) : Vehicle(id, Type::BICYCLE) {
    }
};

class Car: public Vehicle {
  public:
    Car(const std::string &id) : Vehicle(id, Type::CAR) {
    }
};

class Scooter: public Vehicle {
  public:
    Scooter(const std::string &id) : Vehicle(id, Type::SCOOTER) {
    }
};

#endif // VEHICLE_H
