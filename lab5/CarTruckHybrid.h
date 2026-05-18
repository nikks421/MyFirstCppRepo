#pragma once
#include "Car.h"
#include "Truck.h"

class CarTruckHybrid : public Car, public Truck {
public:
    CarTruckHybrid();
    ~CarTruckHybrid();

    int Move() override;
    int ShowInfo() override;
    int StartEngine() override;
    int StartEngine(string mode) override;
}; 
