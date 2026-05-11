#pragma once
#include <string>
using namespace std;

class Vehicle {
private:
    string color;
    int wheels;
    string engineSound;
public:
    Vehicle();
    virtual ~Vehicle();

    virtual int SetColor(std::string vehicle_color);
    virtual int SetWheels(int number_of_wheels);
    virtual int SetEngineSound(std::string sound);

    string GetColor() const;
    int GetWheels() const;
    string GetEngineSound() const;

    virtual int Move();
    virtual int ShowInfo();
    virtual int StartEngine();
};

int run();