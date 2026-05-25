#pragma once
#include "Vehicle.h"

class ElectricCar : virtual public Vehicle {
public:
    ElectricCar();
    virtual ~ElectricCar();

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};