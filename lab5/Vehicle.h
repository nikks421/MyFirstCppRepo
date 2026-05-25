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

    int SetColor(string vehicle_color);
    int SetWheels(int number_of_wheels);
    int SetEngineSound(string sound);

    string GetColor() const;
    int GetWheels() const;
    string GetEngineSound() const;

    virtual int Move();
    virtual int ShowInfo();
    virtual int ShowInfo(string language);
    virtual int StartEngine();
    virtual int StartEngine(string mode);
};
int run();
