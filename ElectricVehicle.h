#pragma once
#pragma once
#include "Vehicle.h"

class ElectricVehicle : virtual public Vehicle {
private:
    int batteryCapacity;
public:
    ElectricVehicle();
    virtual ~ElectricVehicle();

    int SetBatteryCapacity(int capacity);
    int GetBatteryCapacity() const;
    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};