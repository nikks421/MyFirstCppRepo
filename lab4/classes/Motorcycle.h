#pragma once
#include "Vehicle.h"
#include <string>
using namespace std;

class Motorcycle : public Vehicle {
public:
    Motorcycle();
    virtual int Move()  override;
    virtual int ShowInfo()  override;
    virtual int StartEngine()  override;
}; 