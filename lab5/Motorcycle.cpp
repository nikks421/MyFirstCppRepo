#include "Motorcycle.h"
#include <iostream>
using namespace std;

Motorcycle::Motorcycle() {
    cout << "Motorcycle constructor called" << endl;
    SetColor("Black");
    SetWheels(2);
    SetEngineSound("Braap");
}

Motorcycle::~Motorcycle() {
    cout << "Motorcycle destructor called" << endl;
}

int Motorcycle::Move() {
    cout << "Motorcycle is riding on the road" << endl;
    return 1;
}

int Motorcycle::ShowInfo() {
    cout << "[Motorcycle] ";
    Vehicle::ShowInfo();
    return 1;
}

int Motorcycle::StartEngine() {
    cout << "Motorcycle engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}