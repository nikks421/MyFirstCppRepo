#include "CarMotorcycleElectricHybrid.h"
#include <iostream>
using namespace std;

CarMotorcycleElectricHybrid::CarMotorcycleElectricHybrid() {
    cout << "CarMotorcycleElectricHybrid constructor called" << endl;
    SetColor("Neon Green");
    SetWheels(4);
    SetEngineSound("Multi-Vroom-Braap-Whirr");
}

CarMotorcycleElectricHybrid::~CarMotorcycleElectricHybrid() {
    cout << "CarMotorcycleElectricHybrid destructor called" << endl;
}

int CarMotorcycleElectricHybrid::Move() {
    cout << "CarMotorcycleElectricHybrid moves as car, motorcycle or electric car" << endl;
    return 1;
}

int CarMotorcycleElectricHybrid::ShowInfo() {
    cout << "[CarMotorcycleElectricHybrid] ";
    Vehicle::ShowInfo();
    return 1;
}

int CarMotorcycleElectricHybrid::StartEngine() {
    cout << "Multi-hybrid engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}


int CarMotorcycleElectricHybrid::StartEngine(string mode) {
    cout << "Multi-hybrid engine started in " << mode << " mode: " << GetEngineSound() << "!" << endl;
    return 1;
}