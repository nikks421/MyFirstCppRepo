#pragma once

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;

    double area() const;
    bool containsVectorProduct(const Point& P) const;
    bool containsAreaMethod(const Point& P) const;
    bool isDegenerate() const;
};

double distance(const Point& p1, const Point& p2);
bool isOnSegment(const Point& A, const Point& B, const Point& P);
void describePosition(const Triangle& t, const Point& P);
void process();