#include "Car.h"

Car::Car() {
    SetWheels(4);
    SetColor("white");
    SetEngineSound("Br-r-r-r-r");
    cout << "Car constructor called" << endl;
}

Car::~Car() {
    cout << "Car destructor called" << endl;
}

int Car::Move() {
    cout << "Car is driving on the road" << endl;
    return 1;
}

int Car::ShowInfo() {
    cout << "Car: ";
    Vehicle::ShowInfo();
    return 1;
}

int Car::StartEngine() {
    cout << "Car: ";
    Vehicle::StartEngine();
    return 1;
}