#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle() : color("unknown"), wheels(0), engineSound("silence") {}

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

int Vehicle::Move() {
    cout << "Vehicle is moving" << endl;
    return 1;
}
int Vehicle::ShowInfo() {
    cout << "Color: " << color << ", Wheels: " << wheels << ". Engine sound: " << engineSound << endl;
    return 1;
}
int Vehicle::StartEngine() {
    cout << "Engine started. Sound: " << engineSound << endl;
    return 1;
}




