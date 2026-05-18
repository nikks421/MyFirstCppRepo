#pragma once
#include "Vehicle.h"

class Motorcycle : virtual public Vehicle {
public:
    Motorcycle();
    virtual ~Motorcycle();

    virtual int Move() override;
    virtual int ShowInfo() override;  
    virtual int StartEngine() override;
};