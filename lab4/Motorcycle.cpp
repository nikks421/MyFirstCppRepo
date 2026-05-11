#include "Motorcycle.h"
#include <iostream>

Motorcycle::Motorcycle() {
    SetWheels(2);
    SetColor("black");
    SetEngineSound("ring-ring-ring");
}

Motorcycle::~Motorcycle() {
    cout << "Motorcycle destructor called" << std::endl;
}

int Motorcycle::Move() {
    cout << "Motorcycle is riding between cars" << std::endl;
    return 1;
}

int Motorcycle::ShowInfo() {
    cout << "Motorcycle: ";
    Vehicle::ShowInfo();
    return 1;
}

int Motorcycle::StartEngine() {
    cout << "Motorcycle: ";
    Vehicle::StartEngine();
    return 1;
}