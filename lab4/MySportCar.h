#pragma once
#include "SportCar.h"
#include <string>
using namespace std;

class MySportCar : public SportCar {
private:
    string name;
public:
    MySportCar(string turbo_type, string car_name, string car_color);
    virtual ~MySportCar();

    int SetName(string car_name);
    int SetName(int car_name);

    virtual int Move() override;
    virtual int ShowInfo() override;
    virtual int StartEngine() override;
};