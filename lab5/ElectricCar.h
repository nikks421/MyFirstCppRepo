#pragma once
#pragma once
#include "Car.h"
#include "ElectricVehicle.h"

class ElectricCar : public Car, public ElectricVehicle {
private:
    string model;
public:
    ElectricCar(string modelName, string carColor, int battery);
    virtual ~ElectricCar();

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};