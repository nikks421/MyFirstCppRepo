#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car();
    virtual ~Car();

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};