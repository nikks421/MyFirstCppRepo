#pragma once
#include <string>
using namespace std;

class Vehicle {
protected:
    string color;
    int wheels;
    string engineSound;

public:
    Vehicle();
    virtual int SetColor(string vehicle_color);
    virtual int SetWheels(int number_of_wheels);
    virtual int SetEngineSound(string sound);
    virtual int Move();
    virtual int ShowInfo();
    virtual int StartEngine();
    virtual ~Vehicle() {}
};

