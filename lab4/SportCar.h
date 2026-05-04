#pragma once
#include "Car.h"
#include <string>
using namespace std;

class SportCar : public Car {
protected:
    string turbo;

public:
    SportCar();
    SportCar(string turbo_type);
    int SetTurbo(string turbo_type);
    virtual int Move()  override;
    virtual int ShowInfo()  override;
    virtual int StartEngine()  override;
};