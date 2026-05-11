#pragma once
#include "Car.h"
#include "ElectricVehicle.h"


class Amphibious {
private:
    int depthCapacity;      
    string waterSpeed;     

public:
    Amphibious();
    virtual ~Amphibious();

    int SetDepthCapacity(int depth);
    int SetWaterSpeed(string speed);
    int GetDepthCapacity() const;
    string GetWaterSpeed() const;

    virtual int Swim();
    virtual int ShowAmphibiousInfo();
};


class AmphibiousElectricCar : public Car, public ElectricVehicle, public Amphibious {
private:
    string model;
    string specialFeature;

public:
    AmphibiousElectricCar(string modelName, string carColor, int battery, int depth, string waterSpeed);
    virtual ~AmphibiousElectricCar();
    int SetSpecialFeature(string feature);
    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
    virtual int Swim() override;
};