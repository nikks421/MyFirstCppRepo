#pragma once

#include "SportCar.h"
#include <string>
using namespace std;

class MySportCar : public SportCar {
private:
    string name;
    string myColor;

public:
    MySportCar(string turbo_type, string car_name, string car_color);
    int SetName(string car_name);
    int SetName(int car_name);
    virtual int SetColor(string car_color);
    virtual int Move()  override;
    virtual int ShowInfo()  override;
    virtual int StartEngine()  override;
};