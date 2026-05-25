#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>
#include <cmath>

Dyhotomia_class::Dyhotomia_class() {}
Dyhotomia_class::~Dyhotomia_class() {
    std::cout << "Dyhotomia_class deleted" << std::endl;
}

void Dyhotomia_class::setIntervals(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}
void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

bool Dyhotomia_class::hasRoot() {
    auto f = [](double x) {                         
        return (x * x) / 4.0 + x - 1.2502;
        };

    if (f(a) * f(b) > 0) {
        std::cout << "No root in interval (" << a << " : " << b << ")" << std::endl;
        return false;
    }
    return true;
}


double Dyhotomia_class::solveDichotomy() {
    double lo = a, hi = b;

    auto f = [](double x) {                         
        return (x * x) / 4.0 + x - 1.2502;
        };

    double flo = f(lo);
    if (flo * f(hi) > 0) {
        std::cout << "No root in interval [" << lo << ", " << hi << "]." << std::endl;
        return 0;
    }

    auto rootIsLeft = [&](double fc) {              
        return flo * fc < 0;
        };

    auto closeEnough = [&](double fc) {            
        return fabs(fc) < eps;
        };

    int iterations = 0;
    double c = lo, fc = 0;
    while (fabs(hi - lo) > eps && iterations < 100) {
        iterations++;
        c = (lo + hi) / 2.0;
        fc = f(c);

        if (closeEnough(fc)) break;    

        if (rootIsLeft(fc)) {
            hi = c;
        }
        else {
            lo = c;
            flo = fc;
        }
    }

    double x = (lo + hi) / 2.0;
    if (iterations >= 100)
        std::cout << "[Dyhotomia] Max iterations reached. Approximate root: " << x << std::endl;
    else
        std::cout << "[Dyhotomia] Root: x = " << x << std::endl;

    std::cout << "[Dyhotomia] f(x)       = " << f(x) << std::endl;
    std::cout << "[Dyhotomia] Iterations = " << iterations << std::endl;
    return x;
}

void Dyhotomia_class::solveNewton() {
    auto f = [](double x) {                         
        return (x * x) / 4.0 + x - 1.2502;
        };

    auto df = [&](double x) {                      
        constexpr double dx = 1e-6;
        return (f(x + dx) - f(x)) / dx;
        };

    auto newtonStep = [&](double xk) {              
        return xk - f(xk) / df(xk);
        };

    double x = 50.0;
    int iterations = 0;

    while (fabs(f(x)) > eps && iterations < 100) {
        iterations++;
        if (fabs(df(x)) < 1e-9) {
            std::cout << "[Newton] Derivative is zero, stopping." << std::endl;
            std::cout << "[Newton] Last approximation: " << x << std::endl;
            return;
        }
        x = newtonStep(x);
    }

    if (iterations >= 100)
        std::cout << "[Newton] Max iterations reached. Approximate root: " << x << std::endl;
    else
        std::cout << "[Newton] Root: x = " << x << std::endl;

    std::cout << "[Newton] f(x)       = " << f(x) << std::endl;
    std::cout << "[Newton] Iterations = " << iterations << std::endl;
}


void runLab() {
    double a, b, eps;
    std::cout << "Function: x^2/4 + x - 1.2502" << std::endl;
    std::cout << "Enter interval: ";
    std::cin >> a >> b;
    std::cout << "Enter eps: ";
    std::cin >> eps;

    Dyhotomia_class dyh;
    dyh.setIntervals(a, b);
    dyh.setTolerance(eps);

    std::cout << std::fixed << std::setprecision(6);

    if (!dyh.hasRoot()) return;

    std::cout << "\n Dichotomy Method " << std::endl;
    dyh.solveDichotomy();

    std::cout << "\n Newton's Method " << std::endl;
    dyh.solveNewton();
}