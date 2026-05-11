#pragma once
#include "Vehicle.h"

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    virtual ~Motorcycle();

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};