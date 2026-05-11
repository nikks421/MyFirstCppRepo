#include "AmphibiousElectricCar.h"
#include <iostream>
using namespace std;


Amphibious::Amphibious() : depthCapacity(0), waterSpeed("slow") {
    cout << "Amphibious constructor called" << endl;
}

Amphibious::~Amphibious() {
    cout << "Amphibious destructor called" << endl;
}

int Amphibious::SetDepthCapacity(int depth) {
    depthCapacity = depth;
    return 1;
}

int Amphibious::SetWaterSpeed(string speed) {
    waterSpeed = speed;
    return 1;
}

int Amphibious::GetDepthCapacity() const {
    return depthCapacity;
}

string Amphibious::GetWaterSpeed() const {
    return waterSpeed;
}

int Amphibious::Swim() {
    cout << "Amphibious vehicle is swimming in water" << endl;
    return 1;
}

int Amphibious::ShowAmphibiousInfo() {
    cout << "Depth capacity: " << depthCapacity << " meters" << endl;
    cout << "Water speed: " << waterSpeed << endl;
    return 1;
}

AmphibiousElectricCar::AmphibiousElectricCar(string modelName, string carColor, int battery, int depth, string waterSpd)
    : Vehicle(), Car(), ElectricVehicle(), Amphibious() {

    model = modelName;
    SetColor(carColor);
    SetWheels(4);
    SetBatteryCapacity(battery);
    SetDepthCapacity(depth);
    SetWaterSpeed(waterSpd);
    SetEngineSound("electric + water splashing");

    cout << "AmphibiousElectricCar constructor called for: " << model << endl;
}

AmphibiousElectricCar::~AmphibiousElectricCar() {
    cout << "AmphibiousElectricCar destructor called for: " << model << endl;
}

int AmphibiousElectricCar::SetSpecialFeature(string feature) {
    specialFeature = feature;
    return 1;
}

int AmphibiousElectricCar::Move() {
    cout << "Amphibious electric car \"" << model << "\" can drive on land AND swim in water!" << endl;
    return 1;
}

int AmphibiousElectricCar::ShowInfo() {
    cout << "\n AMPHIBIOUS ELECTRIC CAR " << endl;
    cout << "Model: " << model << endl;
    cout << "Color: " << GetColor() << endl;
    cout << "Wheels: " << GetWheels() << endl;
    cout << "Engine sound: " << GetEngineSound() << endl;
    cout << "Battery capacity: " << GetBatteryCapacity() << "%" << endl;
    cout << "Depth capacity: " << GetDepthCapacity() << " meters" << endl;
    cout << "Water speed: " << GetWaterSpeed() << endl;
    if (!specialFeature.empty()) {
        cout << "Special feature: " << specialFeature << endl;
    }
    return 1;
}

int AmphibiousElectricCar::StartEngine() {
    cout << model << ": ";
    Vehicle::StartEngine();
    cout << " (Ready for land or water!)" << endl;
    return 1;
}

int AmphibiousElectricCar::Swim() {
    cout << model << " is swimming in water! Max depth: " << GetDepthCapacity() << " meters" << endl;
    return 1;
}