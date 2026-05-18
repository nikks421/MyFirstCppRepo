#pragma once
#include "Vehicle.h"

class Truck : virtual public Vehicle {
public:
    Truck();
    virtual ~Truck();

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};
