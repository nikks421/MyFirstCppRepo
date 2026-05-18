#pragma once
#include "Car.h"
#include "Motorcycle.h"
#include "ElectricCar.h"

class CarMotorcycleElectricHybrid : public Car, public Motorcycle, public ElectricCar {
public:
    CarMotorcycleElectricHybrid();
    ~CarMotorcycleElectricHybrid();

    int Move() override;
    int ShowInfo() override;
    int StartEngine() override;
    int StartEngine(string mode) override;
};