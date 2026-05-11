#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

double Dyhotomia_class::function(double x) {
    if (x != 0) {
        return (x * x) / 4.0 + x - 1.2502;
    }
    return 0;
}

double Dyhotomia_class::derivative(double x) {
    double dx = 1e-6;
    return (function(x + dx) - function(x)) / dx;
}

bool Dyhotomia_class::hasRoot(double a, double b) {
    double fa = function(a);
    double fb = function(b);
    return (fa * fb <= 0);
}

double Dyhotomia_class::solveDichotomy(double a, double b, double eps) {
    double temp_a = a, temp_b = b;
    double fa = function(temp_a);
    double fb = function(temp_b);
    double c, fc;

    if (fa * fb > 0) {
        cout << "No root in the interval [" << temp_a << ", " << temp_b << "]." << endl;
        return 0;
    }

    while ((temp_b - temp_a) > eps) {
        c = (temp_a + temp_b) / 2;
        fc = function(c);

        if (fabs(fc) < eps) {
            return c;
        }

        if (fa * fc < 0) {
            temp_b = c;
            fb = fc;
        }
        else {
            temp_a = c;
            fa = fc;
        }
    }
    return (temp_a + temp_b) / 2;
}

void Dyhotomia_class::solveNewton(double a, double b, double eps) {
    double x = 10000.0;
    int maxIter = 1000;
    int iter = 0;

    while (abs(function(x)) > eps && iter < maxIter) {
        double dfx = derivative(x);

        if (abs(dfx) < 1e-16) {
            cout << "Derivative is zero, stopping" << endl;
            cout << "Last computed approximation: " << x << endl;
            return;
        }

        x = x - function(x) / dfx;
        iter++;
    }

    if (iter >= maxIter) {
        cout << "Warning: Maximum number of iterations reached" << endl;
    }

    cout << "Root: x = " << x << endl;
    cout << "Function value: f(x) = " << function(x) << endl;
    cout << "Iter =" << iter << endl;
}

void runLab() {
    double a, b, eps;
    Dyhotomia_class dyh;

    cout << "Function:x^2/4 + x - 1.2502 " << endl;

    cout << "\nEnter the left endpoint of the interval a: ";
    cin >> a;
    cout << "Enter the right endpoint of the interval b: ";
    cin >> b;
    cout << "Enter the precision eps: ";
    cin >> eps;

    if (!dyh.hasRoot(a, b)) {
        cout << "\nNo root in the interval [" << a << ", " << b << "]." << endl;
    }
    else {
        cout << fixed << setprecision(6);

        double rootDich = dyh.solveDichotomy(a, b, eps);
        cout << "\nDyhotomia Method" << endl;
        cout << "Root: x = " << rootDich << endl;
        cout << "Function value: f(x) = " << dyh.function(rootDich) << endl;

        cout << "\nNewton's Method:" << endl;
        dyh.solveNewton(a, b, eps);
    }
}