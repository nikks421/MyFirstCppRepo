#pragma once


class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;
public:
    Dyhotomia_class(void);
    ~Dyhotomia_class(void);

    void setIntervals(double vol_a, double vol_b);
    void setTolerance(double vol_eps);

    bool hasRoot();
    double solveDichotomy();
    void solveNewton();
};

void runLab();