#include "Car.h"
#include "SportCar.h"
#include "MySportCar.h"
#include "Motorcycle.h"
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

int run() {
    Vehicle* vehicles[4];
    vehicles[0] = new Car();
    vehicles[1] = new SportCar("twin-turbo");
    vehicles[2] = new MySportCar("electric", "Tesla", "blue");
    vehicles[3] = new Motorcycle();

    for (int i = 0; i < 4; i++) {
        vehicles[i]->Move();     
        vehicles[i]->StartEngine();
        delete vehicles[i];
    }

    return 0;
}


