#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class Car : public Vehicle {
public:
    Car();
    virtual int Move() override;
    virtual int ShowInfo()  override;
    virtual int StartEngine()  override;
};