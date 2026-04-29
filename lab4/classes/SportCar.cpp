#include "SportCar.h"
#include <iostream>
using namespace std;

SportCar::SportCar() : Car() {
    turbo = "none";
}

SportCar::SportCar(string turbo_type) {
    SetTurbo(turbo_type);
    SetWheels(4);
    SetColor("red");
    SetEngineSound("VROOM-VROOM-VROOM");
}

int SportCar::SetTurbo(string turbo_type) {
    turbo = turbo_type;
    return 1;
}

int SportCar::Move() {
    cout << "Sport car is racing at huge speed!" << endl;
    return 1;
}

int SportCar::ShowInfo() {
    cout << "Sport car with turbo " << turbo << ": ";
    Vehicle::ShowInfo();
    return 1;
}

int SportCar::StartEngine() {
    cout << "Sport car with turbo " << turbo << ": VROOM-VROOM-VROOM!!!" << endl;
    return 1;
}