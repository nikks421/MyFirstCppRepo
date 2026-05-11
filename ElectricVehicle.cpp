#include "ElectricVehicle.h"

ElectricVehicle::ElectricVehicle() : batteryCapacity(100) {
    SetEngineSound("whirrrrr");
    cout << "ElectricVehicle constructor called" << endl;
}

ElectricVehicle::~ElectricVehicle() {
    cout << "ElectricVehicle destructor called" << endl;
}

int ElectricVehicle::SetBatteryCapacity(int capacity) {
    batteryCapacity = capacity;
    return 1;
}

int ElectricVehicle::GetBatteryCapacity() const {
    return batteryCapacity;  
}

int ElectricVehicle::Move() {
    cout << "Electric vehicle moves silently" << endl;
    return 1;
}

int ElectricVehicle::ShowInfo() {
    cout << "ElectricVehicle (battery: " << batteryCapacity << "%): ";
    Vehicle::ShowInfo();
    return 1;
}

int ElectricVehicle::StartEngine() {
    cout << "ElectricVehicle: ";
    Vehicle::StartEngine();
    return 1;
}