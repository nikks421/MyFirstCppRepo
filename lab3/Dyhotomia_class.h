#pragma once

class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;

public:
    Dyhotomia_class(void);
    Dyhotomia_class(double vol_a, double vol_b, double vol_eps);
    ~Dyhotomia_class(void);

    void setVolumes(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    double function(double x);
    double derivative(double x);

    bool hasRoot(void);
    double solveDichotomy(void);
    double solveNewton(void);
};

void runLab();