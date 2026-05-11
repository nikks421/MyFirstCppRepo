#include "ElectricCar.h"

ElectricCar::ElectricCar(string modelName, string carColor, int battery)
    : Vehicle(), Car(), ElectricVehicle() {
    model = modelName;
    SetColor(carColor);
    SetWheels(4);
    SetBatteryCapacity(battery);
    SetEngineSound("electric hummm");
    cout << "ElectricCar constructor called" << endl;
}

ElectricCar::~ElectricCar() {
    cout << "ElectricCar destructor called" << endl;
}

int ElectricCar::Move() {
    cout << "Electric car \"" << model << "\" zooms silently!" << endl;
    return 1;
}

int ElectricCar::ShowInfo() {
    cout << "ELECTRIC CAR: " << model << endl;
    cout << "  ";
    Vehicle::ShowInfo();
    cout << "  Battery: " << GetBatteryCapacity() << "%" << endl;
    return 1;
}

int ElectricCar::StartEngine() {
    cout << model << ": ";
    Vehicle::StartEngine();
    return 1;
}