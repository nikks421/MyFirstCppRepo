#include "MySportCar.h"
#include <iostream>
using namespace std;

MySportCar::MySportCar(string turbo_type, string car_name, string car_color)
    : SportCar()
{
    SetTurbo(turbo_type);
    SetColor(car_color);
    SetName(car_name);
    SetWheels(4);
    SetEngineSound("RRRRR-VROOM-VROOM-TURBO");
}

MySportCar::~MySportCar() {
    std::cout << "MySportCar destructor called" << std::endl;
}

int MySportCar::SetName(string car_name) {
    name = car_name;
    return 1;
}

int MySportCar::SetName(int car_name) {
    name = to_string(car_name);
    return 1;
}

int MySportCar::Move() {
    std::cout << "My sport car \"" << name << "\" flies like a lightning!" << std::endl;
    return 1;
}

int MySportCar::ShowInfo() {
    cout << "MY CAR" << std::endl;
    cout << "  Name:  " << name << std::endl;
    cout << "  Turbo: " << turbo << std::endl;
    cout << "  ";
    Vehicle::ShowInfo();   // виводить color, wheels, engineSound через геттери
    return 1;
}

int MySportCar::StartEngine() {
    cout << "My \"" << name << "\" (turbo: " << turbo << "): ";
    Vehicle::StartEngine();
    return 1;
}