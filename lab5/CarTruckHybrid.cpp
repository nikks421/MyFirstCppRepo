#include "CarTruckHybrid.h"
#include <iostream>
using namespace std;

CarTruckHybrid::CarTruckHybrid() {
    cout << "CarTruckHybrid constructor called" << endl;
    SetColor("Orange");
    SetWheels(6);
    SetEngineSound("Hybrid Rumble");
}

CarTruckHybrid::~CarTruckHybrid() {
    cout << "CarTruckHybrid destructor called" << endl;
}

int CarTruckHybrid::Move() {
    cout << "CarTruckHybrid moves like a car or truck" << endl;
    return 1;
}

int CarTruckHybrid::ShowInfo() {
    cout << "[CarTruckHybrid] ";
    Vehicle::ShowInfo();
    return 1;
}

int CarTruckHybrid::StartEngine() {
    cout << "CarTruckHybrid engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}


int CarTruckHybrid::StartEngine(string mode) {
    cout << "CarTruckHybrid engine started in " << mode << " mode: " << GetEngineSound() << "!" << endl;
    return 1;
}