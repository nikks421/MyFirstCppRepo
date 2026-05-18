#include "Car.h"
#include <iostream>
using namespace std;

Car::Car() {
    cout << "Car constructor called" << endl;
    SetColor("Red");
    SetWheels(4);
    SetEngineSound("Vroom");
}

Car::~Car() {
    cout << "Car destructor called" << endl;
}

int Car::Move() {
    cout << "Car is driving on the road" << endl;
    return 1;
}

int Car::ShowInfo() {
    cout << "[Car] ";
    Vehicle::ShowInfo();
    return 1;
}

int Car::StartEngine() {
    cout << "Car engine started: " << GetEngineSound() << "!" << endl;
    return 1;
}

int Car::StartEngine(string mode) {
    cout << "Car engine started in " << mode << " mode: " << GetEngineSound() << "!" << endl;
    return 1;
}