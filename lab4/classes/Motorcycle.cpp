#include "Motorcycle.h"
#include <iostream>
using namespace std;

Motorcycle::Motorcycle() {
    SetWheels(2);
    SetColor("black");
    SetEngineSound("ring-ring-ring");
    ShowInfo();
    Move();
    StartEngine();
}

int Motorcycle::Move() {
    cout << "Motorcycle is riding between cars" << endl;
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