#include "Truck.h"
#include <iostream>
using namespace std;

Truck::Truck() {
    cout << "Truck constructor called" << endl;
    SetColor("Blue");
    SetWheels(6);
    SetEngineSound("Rumble");
}

Truck::~Truck() {
    cout << "Truck destructor called" << endl;
}

int Truck::Move() {
    cout << "Truck is hauling cargo" << endl;
    return 1;
}

int Truck::ShowInfo() {
    cout << "[Truck] ";
    Vehicle::ShowInfo();
    return 1;
}

int Truck::StartEngine() {
    cout << "Truck engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}