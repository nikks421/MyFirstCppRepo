#include "Vehicle.h"
#include "CarMotorcycleElectricHybrid.h"
#include "CarTruckHybrid.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle() : color("unknown"), wheels(0), engineSound("silence") {
    cout << "Vehicle constructor called" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destructor called" << endl;
}

int Vehicle::SetColor(string vehicle_color) {
    color = vehicle_color;
    return 1;
}

int Vehicle::SetWheels(int number_of_wheels) {
    wheels = number_of_wheels;
    return 1;
}

int Vehicle::SetEngineSound(string sound) {
    engineSound = sound;
    return 1;
}

string Vehicle::GetColor() const { return color; }
int Vehicle::GetWheels() const { return wheels; }
string Vehicle::GetEngineSound() const { return engineSound; }

int Vehicle::Move() {
    cout << "Vehicle is moving" << endl;
    return 1;
}

int Vehicle::ShowInfo() {
    cout << "Color: " << color << ", Wheels: " << wheels
        << ", Engine sound: " << engineSound << endl;
    return 1;
}

int Vehicle::ShowInfo(string language) {
    cout << "VEHICLE INFO (Language: " << language << ")" << endl;
    cout << "Color: " << color << ", Wheels: " << wheels
        << ", Engine sound: " << engineSound << endl;
    return 1;
}

int Vehicle::StartEngine() {
    cout << "Engine started. Sound: " << engineSound << endl;
    return 1;
}

int Vehicle::StartEngine(string mode) {
    cout << "Engine started in " << mode << " mode. Sound: " << engineSound << endl;
    return 1;
}

int run() {
    cout << "Constructors" << endl;
    CarMotorcycleElectricHybrid* vehicle1 = new CarMotorcycleElectricHybrid();
    vehicle1->ShowInfo();
    vehicle1->StartEngine();
    vehicle1->StartEngine("Who started this engine?");

    cout << "Destructors" << endl;
    delete vehicle1;
    cout << endl;

    cout << "Constructors" << endl;
    CarTruckHybrid* vehicle2 = new CarTruckHybrid();
    vehicle2->ShowInfo();
    vehicle2->StartEngine();
    vehicle2->StartEngine("Who started this engine?");
    cout << "Destructors" << endl;
    delete vehicle2;
    cout << endl;
    return 0;
}

