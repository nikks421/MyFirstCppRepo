#pragma once
#include <string>
#include <iostream>
using namespace std;

class Vehicle {
private:
    string color;
    int wheels;
    string engineSound;
public:
    Vehicle();
    virtual ~Vehicle();

    virtual int SetColor(string vehicle_color);
    virtual int SetWheels(int number_of_wheels);
    virtual int SetEngineSound(string sound);

    string GetColor() const;
    int GetWheels() const;
    string GetEngineSound() const;

    virtual int Move();
    virtual int ShowInfo();
    virtual int StartEngine();
};

int run();