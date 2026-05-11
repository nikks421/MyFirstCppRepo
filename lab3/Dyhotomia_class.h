#pragma once

class Dyhotomia_class {
private:
    double a;
    double b;
    double eps;

public:
    double function(double x);
    double derivative(double x);
    bool hasRoot(double a, double b);
    double solveDichotomy(double a, double b, double eps);
    void solveNewton(double a, double b, double eps);
};

void runLab();
