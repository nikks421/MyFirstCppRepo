#include "Dyhotomia_class.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

Dyhotomia_class::Dyhotomia_class(void) {
    a = 0.0;
    b = 0.0;
    eps = 0.001;
}

Dyhotomia_class::Dyhotomia_class(double vol_a, double vol_b, double vol_eps) {
    a = vol_a;
    b = vol_b;
    eps = vol_eps;
}

Dyhotomia_class::~Dyhotomia_class(void) {}

void Dyhotomia_class::setVolumes(double vol_a, double vol_b) {
    a = vol_a;
    b = vol_b;
}

void Dyhotomia_class::setTolerance(double vol_eps) {
    eps = vol_eps;
}

double Dyhotomia_class::function(double x) {
    if (x != 0) {
        return cos(2.0 / x) - 2.0 * sin(1.0 / x) + 1.0 / x;
    }
    return 0;
}

double Dyhotomia_class::derivative(double x) {
    double dx = 1e-7;
    return (function(x + dx) - function(x)) / dx;
}

bool Dyhotomia_class::hasRoot(void) {
    double fa = function(a);
    double fb = function(b);
    return (fa * fb <= 0);
}

double Dyhotomia_class::solveDichotomy(void) {
    double temp_a = a, temp_b = b;
    double fa = function(temp_a);
    double fb = function(temp_b);
    double c, fc;

    if (fa * fb > 0) {
        cout << "Немає кореня на проміжку [" << temp_a << ", " << temp_b << "]." << endl;
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

double Dyhotomia_class::solveNewton(void) {
    double x0 = (a + b) / 2;
    double x1;
    int maxIter = 1000;

    for (int i = 0; i < maxIter; i++) {
        double fx = function(x0);
        double dfx = derivative(x0);

        if (fabs(dfx) < 1e-12) {
            cout << "Помилка: похідна близька до нуля!" << endl;
            return 0;
        }

        x1 = x0 - fx / dfx;

        if (fabs(x1 - x0) < eps) {
            return x1;
        }
        x0 = x1;
    }

    cout << "Попередження: досягнуто максимальну кількість ітерацій" << endl;
    return x0;
}

void runLab() {
    double a, b, eps;
    cout << "Функція: cos(2/x) - 2*sin(1/x) + 1/x" << endl;

    cout << "\nВведіть ліву межу проміжку a: ";
    cin >> a;
    cout << "Введіть праву межу проміжку b: ";
    cin >> b;
    cout << "Введіть точність eps: ";
    cin >> eps;

    Dyhotomia_class* dyh = new Dyhotomia_class(a, b, eps);

    if (!dyh->hasRoot()) {
        cout << "\nНемає кореня на проміжку [" << a << ", " << b << "]." << endl;
    }
    else {
        cout << fixed << setprecision(6);

        double rootDich = dyh->solveDichotomy();
        cout << "\nМетод Дихотомії" << endl;
        cout << "Корінь: x = " << rootDich << endl;
        cout << "Значення функції: f(x) = " << dyh->function(rootDich) << endl;

        double rootNewton = dyh->solveNewton();
        cout << "\nМетод Ньютона: " << endl;
        cout << "Корінь: x = " << rootNewton << endl;
        cout << "Значення функції: f(x) = " << dyh->function(rootNewton) << endl;
    }

    delete dyh;
}