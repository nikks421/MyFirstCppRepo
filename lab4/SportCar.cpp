#include "SportCar.h"
#include <iostream>

SportCar::SportCar() : Car(), turbo("none") {}

SportCar::SportCar(std::string turbo_type) : Car() {
    SetTurbo(turbo_type);
    SetColor("red");
    SetEngineSound("VROOM-VROOM-VROOM");
}

SportCar::~SportCar() {
    cout << "SportCar destructor called" << endl;
}

int SportCar::SetTurbo(std::string turbo_type) {
    turbo = turbo_type;
    return 1;
}

int SportCar::Move() {
    cout << "Sport car is racing at huge speed!" << endl;
    return 1;
}

int SportCar::ShowInfo() {
    std::cout << "Sport car (turbo: " << turbo << "): ";
    Vehicle::ShowInfo();
    return 1;
}

int SportCar::StartEngine() {
    cout << "Sport car (turbo: " << turbo << "): VROOM-VROOM-VROOM!!!" << endl;
    return 1;
}