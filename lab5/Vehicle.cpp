#include "Vehicle.h"
#include "AmphibiousElectricCar.h"
Vehicle::Vehicle() : color("unknown"), wheels(0), engineSound("silence") {
    cout << "Vehicle constructor called" << endl;
}

Vehicle::~Vehicle() {
    cout << "Vehicle destructor called" << endl;
}

int Vehicle::SetColor(string vehicle_color) {
    color = vehicle_color;
    return 1;
}

int Vehicle::SetWheels(int number_of_wheels) {
    wheels = number_of_wheels;
    return 1;
}

int Vehicle::SetEngineSound(string sound) {
    engineSound = sound;
    return 1;
}

string Vehicle::GetColor() const { return color; }
int Vehicle::GetWheels() const { return wheels; }
string Vehicle::GetEngineSound() const { return engineSound; }

int Vehicle::Move() {
    cout << "Vehicle is moving" << endl;
    return 1;
}

int Vehicle::ShowInfo() {
    cout << "Color: " << color << ", Wheels: " << wheels
        << ", Engine sound: " << engineSound << endl;
    return 1;
}

int Vehicle::StartEngine() {
    cout << "Engine started. Sound: " << engineSound << endl;
    return 1;
}

int run() {
    cout << "\n DEMONSTRATION OF MULTIPLE INHERITANCE \n" << endl;

    cout << " Creating an object AmphibiousElectricCar " << endl;
    AmphibiousElectricCar myCar("AquaTesla 3000", "cyan", 85, 15, "50 km/h");

    cout << "\nCall methods " << endl;
    myCar.ShowInfo();
    myCar.Move();
    myCar.StartEngine();
    myCar.Swim();

    cout << "\nProgram termination (destructors will be called automatically)" << endl;

    return 0;
}