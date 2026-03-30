#include "Header.h"
#include <cmath>
#include <iostream>

using namespace std;

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

double heronArea(const Triangle& t) {
    double a = distance(t.A, t.B);
    double b = distance(t.B, t.C);
    double c = distance(t.C, t.A);
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::area() const {
    return heronArea(*this);
}

bool Triangle::containsVectorProduct(const Point& P) {
    double d1 = (B.x - A.x) * (P.y - A.y) - (B.y - A.y) * (P.x - A.x);
    double d2 = (C.x - B.x) * (P.y - B.y) - (C.y - B.y) * (P.x - B.x);
    double d3 = (A.x - C.x) * (P.y - C.y) - (A.y - C.y) * (P.x - C.x);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
    return !(hasNeg && hasPos);
}

bool Triangle::isDegenerate() const {
    return area() < 1e-9;
}

bool isOnSegment(const Point& A, const Point& B, const Point& P) {
    double cross = (P.x - A.x) * (B.y - A.y) - (P.y - A.y) * (B.x - A.x);
    if (fabs(cross) > 1e-9) return false;

    double dot = (P.x - A.x) * (B.x - A.x) + (P.y - A.y) * (B.y - A.y);
    if (dot < 0) return false;

    double squaredLength = (B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y);
    if (dot > squaredLength) return false;

    return true;
}

bool Triangle::contains(const Point& P) const {
    
    if (isDegenerate()) return false;

   
    if ((fabs(P.x - A.x) < 1e-9 && fabs(P.y - A.y) < 1e-9) ||
        (fabs(P.x - B.x) < 1e-9 && fabs(P.y - B.y) < 1e-9) ||
        (fabs(P.x - C.x) < 1e-9 && fabs(P.y - C.y) < 1e-9)) {
        return true;
    }

   
    if (isOnSegment(A, B, P) || isOnSegment(B, C, P) || isOnSegment(C, A, P)) {
        return true;
    }

   
    Triangle T1 = { A, B, P };
    Triangle T2 = { B, C, P };
    Triangle T3 = { C, A, P };

    double S_main = area();
    double S_sum = T1.area() + T2.area() + T3.area();

    return fabs(S_main - S_sum) <= 1e-9;
}


void describePosition(const Triangle& t, const Point& P) {
    if ((fabs(P.x - t.A.x) < 1e-9 && fabs(P.y - t.A.y) < 1e-9) ||
        (fabs(P.x - t.B.x) < 1e-9 && fabs(P.y - t.B.y) < 1e-9) ||
        (fabs(P.x - t.C.x) < 1e-9 && fabs(P.y - t.C.y) < 1e-9)) {
        cout << "Точка є вершиною трикутника" << endl;
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
    if (t.contains(P)) {
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


    if (t.isDegenerate()) {
        cout << "\nПомилка: Трикутник вироджений (площа = 0)!" << endl;
        cout << "Завершення програми." << endl;
        return;
    }
    cout << "Трикутник не вироджений." << endl;

    int numPoints;
    cout << "\nСкільки точок ви хочете перевірити? ";
    cin >> numPoints;
    for (int i = 0; i < numPoints; i++) {
        cout << "\nТочка " << i + 1 << endl;
        Point p;
        cout << "Введіть координати точки (x y): ";
        cin >> p.x >> p.y;

        bool resultArea = t.contains(p);
        bool resultVector = t.containsVectorProduct(p);

        cout << "\nРезультати двох методів:" << endl;
        cout << "Метод площ:            " << (resultArea ? "точка належить трикутнику" : "точка не належить") << endl;
        cout << "Векторний добуток:     " << (resultVector ? "точка належить трикутнику" : "точка не належить") << endl;

        cout << endl;
        describePosition(t, p);
    }

    cout << "\nПрограма завершена." << endl;
}