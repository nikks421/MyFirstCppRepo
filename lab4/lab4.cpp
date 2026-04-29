#include "MySportCar.h"
#include <iostream>
int main() {
    MySportCar* my_car = new MySportCar("Twin-Turbo V8", "Lightning", "red");
    delete my_car;
    return 0;
}
