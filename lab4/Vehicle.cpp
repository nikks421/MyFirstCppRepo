#include "Vehicle.h"
#include "Car.h"
#include "SportCar.h"
#include "MySportCar.h"
#include "Motorcycle.h"
#include <iostream>

Vehicle::Vehicle() : color("unknown"), wheels(0), engineSound("silence") {}

Vehicle::~Vehicle() {
    std::cout << "Vehicle destructor called" << std::endl;
}

int Vehicle::SetColor(std::string vehicle_color) {
    color = vehicle_color;
    return 1;
}

int Vehicle::SetWheels(int number_of_wheels) {
    wheels = number_of_wheels;
    return 1;
}

int Vehicle::SetEngineSound(std::string sound) {
    engineSound = sound;
    return 1;
}

std::string Vehicle::GetColor() const {
    return color;
}

int Vehicle::GetWheels() const {
    return wheels;
}

std::string Vehicle::GetEngineSound() const {
    return engineSound;
}

int Vehicle::Move() {
    std::cout << "Vehicle is moving" << std::endl;
    return 1;
}

int Vehicle::ShowInfo() {
    std::cout << "Color: " << color
        << ", Wheels: " << wheels
        << ", Engine sound: " << engineSound << std::endl;
    return 1;
}

int Vehicle::StartEngine() {
    std::cout << "Engine started. Sound: " << engineSound << std::endl;
    return 1;
}

int run() {
    Vehicle* vehicles[4];
    vehicles[0] = new Car();
    vehicles[1] = new SportCar("twin-turbo");
    vehicles[2] = new MySportCar("electric", "Tesla", "blue");
    vehicles[3] = new Motorcycle();

    for (int i = 0; i < 4; i++) {
        vehicles[i]->ShowInfo();
        vehicles[i]->Move();
        vehicles[i]->StartEngine();
        std::cout << std::endl;
        delete vehicles[i];
    }
    return 0;
}