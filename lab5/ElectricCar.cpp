#include "ElectricCar.h"
#include <iostream>
using namespace std;

ElectricCar::ElectricCar() {
    cout << "ElectricCar constructor called" << endl;
    SetColor("White");
    SetWheels(4);
    SetEngineSound("Whirr");
}

ElectricCar::~ElectricCar() {
    cout << "ElectricCar destructor called" << endl;
}

int ElectricCar::Move() {
    cout << "Electric car moves silently" << endl;
    return 1;
}

int ElectricCar::ShowInfo() {
    cout << "[ElectricCar] ";
    Vehicle::ShowInfo();
    return 1;
}

int ElectricCar::StartEngine() {
    cout << "Electric car engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}