#include "Header.h"
#include <cmath>
#include <iostream>
using namespace std;

double distance(const Point& p1, const Point& p2) {
    return hypot(p2.x - p1.x, p2.y - p1.y);
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    double underSqrt = s * (s - a) * (s - b) * (s - c);

    if (underSqrt < 0 && underSqrt > -1e-12) {
        return 0.0;
    }
    return sqrt(underSqrt);
}

double Triangle::area() const {
    return 0.5 * fabs((B.x - A.x) * (C.y - A.y) - (C.x - A.x) * (B.y - A.y));
}

bool Triangle::isDegenerate() const {
    return area() < 1e-12;
}

bool Triangle::containsAreaMethod(const Point& P) const {
    if (isDegenerate()) {
        return isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P);
    }

    if ((fabs(P.x - A.x) < 1e-12 && fabs(P.y - A.y) < 1e-12) ||
        (fabs(P.x - B.x) < 1e-12 && fabs(P.y - B.y) < 1e-12) ||
        (fabs(P.x - C.x) < 1e-12 && fabs(P.y - C.y) < 1e-12)) {
        return true;
    }

    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return true;
    }

    double S_main = area();
    double S_sum = heronArea({ A, B, P }) + heronArea({ B, C, P }) + heronArea({ C, A, P });

    return fabs(S_main - S_sum) <= 1e-10;
}

bool Triangle::containsVectorProduct(const Point& P) const {
    if (isDegenerate()) {
        return isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P);
    }

    auto cross_product = [](const Point& a, const Point& b, const Point& c) {
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        };

    double cp1 = cross_product(A, B, P);
    double cp2 = cross_product(B, C, P);
    double cp3 = cross_product(C, A, P);

    double eps = 1e-12;
    bool hasNeg = (cp1 < -eps) || (cp2 < -eps) || (cp3 < -eps);
    bool hasPos = (cp1 > eps) || (cp2 > eps) || (cp3 > eps);
    return !(hasNeg && hasPos);
}

bool isOnSegment(const Point& A, const Point& B, const Point& P) {
    double cross = (P.x - A.x) * (B.y - A.y) - (P.y - A.y) * (B.x - A.x);
    if (fabs(cross) > 1e-12) return false;

    if ((P.x >= A.x - 1e-12 && P.x <= B.x + 1e-12) || (P.x >= B.x - 1e-12 && P.x <= A.x + 1e-12)) {
        if ((P.y >= A.y - 1e-12 && P.y <= B.y + 1e-12) || (P.y >= B.y - 1e-12 && P.y <= A.y + 1e-12)) {
            return true;
        }
    }
    return false;
}

void describePosition(const Triangle& t, const Point& P) {
    double eps = 1e-12;

    if (fabs(P.x - t.A.x) < eps && fabs(P.y - t.A.y) < eps) {
        cout << "Точка є вершиною A" << endl;
        return;
    }
    if (fabs(P.x - t.B.x) < eps && fabs(P.y - t.B.y) < eps) {
        cout << "Точка є вершиною B" << endl;
        return;
    }
    if (fabs(P.x - t.C.x) < eps && fabs(P.y - t.C.y) < eps) {
        cout << "Точка є вершиною C" << endl;
        return;
    }

    if (isOnSegment(t.A, t.B, P)) {
        cout << "Точка лежить на стороні AB" << endl;
        return;
    }
    if (isOnSegment(t.B, t.C, P)) {
        cout << "Точка лежить на стороні BC" << endl;
        return;
    }
    if (isOnSegment(t.C, t.A, P)) {
        cout << "Точка лежить на стороні CA" << endl;
        return;
    }
    if (t.containsAreaMethod(P)) {
        cout << "Точка всередині трикутника" << endl;
    }
    else {
        cout << "Точка поза трикутником" << endl;
    }
}

void process() {
    Triangle t;
    cout << "Введіть координати трикутника:" << endl;
    cout << "A (x y): "; cin >> t.A.x >> t.A.y;
    cout << "B (x y): "; cin >> t.B.x >> t.B.y;
    cout << "C (x y): "; cin >> t.C.x >> t.C.y;

    cout << "\nІнформація про трикутник" << endl;
    cout << "Сторони трикутника:" << endl;
    cout << "AB = " << distance(t.A, t.B) << endl;
    cout << "BC = " << distance(t.B, t.C) << endl;
    cout << "CA = " << distance(t.C, t.A) << endl;
    cout << "Периметр = " << (distance(t.A, t.B) + distance(t.B, t.C) + distance(t.C, t.A)) << endl;
    cout << "Площа = " << t.area() << endl;

    bool degenerate = t.isDegenerate();

    if (degenerate) {
        cout << "\nТрикутник вироджений (площа = 0)!" << endl;
    }
    else {
        cout << "\nТрикутник не вироджений." << endl;
    }

    int numPoints;
    cout << "\nСкільки точок ви хочете перевірити? ";
    cin >> numPoints;

    for (int i = 0; i < numPoints; i++) {
        cout << "\nТочка " << i + 1 << endl;
        Point p;
        cout << "Введіть координати точки (x y): ";
        cin >> p.x >> p.y;

        bool resultArea = t.containsAreaMethod(p);
        bool resultVector = t.containsVectorProduct(p);
        cout << "Метод площ:        " << (resultArea ? "точка належить" : "точка не належить") << endl;
        cout << "Векторний метод:     " << (resultVector ? "точка належить" : "точка не належить") << endl;
        cout << endl;

        if (degenerate) {
            if (resultArea || resultVector) {
                cout << "Точка лежить на межі виродженого трикутника" << endl;
            }
            else {
                cout << "Точка поза виродженим трикутником" << endl;
            }
        }
        else {
            describePosition(t, p);
        }
    }

    cout << "\nПрограма завершена" << endl;
}