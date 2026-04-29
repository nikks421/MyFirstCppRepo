#include "MySportCar.h"
#include <iostream>
using namespace std;

MySportCar::MySportCar(string turbo_type, string car_name, string car_color) {
    SetTurbo(turbo_type);
    SetColor(car_color);
    SetName(car_name);
    SetWheels(4);
    SetEngineSound("RRRRR-VROOM-VROOM-TURBO");
    ShowInfo();
    Move();
    StartEngine();
}

int MySportCar::SetName(string car_name) {
    name = car_name;
    return 1;
}

int MySportCar::SetName(int car_name) {
    name = to_string(car_name);
    return 1;
}

int MySportCar::SetColor(string car_color) {
    myColor = car_color;
    Vehicle::SetColor(car_color);
    return 1;
}

int MySportCar::Move() {
    cout << "My sport car \"" << name << "\" flies like a lightning!" << endl;
    return 1;
}

int MySportCar::ShowInfo() {
    cout << "\nMY CAR" << endl;
    cout << "Name: " << name << endl;
    cout << "Color: " << myColor << endl;
    cout << "Turbo: " << turbo << endl;
    return 1;
}

int MySportCar::StartEngine() {
    cout << "My " << name << " with turbo " << turbo << ": ";
    Vehicle::StartEngine();
    return 1;
}