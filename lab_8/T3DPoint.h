#pragma once

#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <string>
#include "TPointArrays_errors.h"

class T3DPoint {
private:
    static const double MIN_val;
    static const double MAX_val;
    double x, y, z;

public:
    T3DPoint() {
        x = y = z = 0;
    }
    T3DPoint(double xx, double yy, double zz)
    {
        x = xx;
        y = yy;
        z = zz;
    }
    T3DPoint(const T3DPoint& other) {
        x = other.x;
        y = other.y;
        z = other.z;
    }

    static const double GetMin_val() { return MIN_val; }
    static const double GetMax_val() { return MAX_val; }

    double GetX() const { return x; }
    double GetY() const { return y; }
    double GetZ() const { return z; }

    void print(std::ostream& out) const {
        out << "(" << x << ", " << y << ", " << z << ")";
    }

    void scan(std::istream& in) {
        double xx, yy, zz;
        in >> xx >> yy >> zz;

        x = xx;
        y = yy;
        z = zz;
    }

    T3DPoint operator + (const T3DPoint& other) const
    {
        return T3DPoint(x + other.x, y + other.y, z + other.z);
    }

    T3DPoint operator - (const T3DPoint& other) const
    {
        return T3DPoint(x - other.x, y - other.y, z - other.z);
    }

    T3DPoint operator / (double number) const
    {
        return T3DPoint(x / number, y / number, z / number);
    }

    double abs() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    bool operator==(const int a) const {
        return x == a || y == a || z == a;
    }

    bool operator>=(const T3DPoint& other) const {
        return x >= other.x;
    }

    bool operator>(const int a) const {
        return x > a || y > a || z > a;
    }

    bool operator<(const int a) const {
        return x < a || y < a || z < a;
    }

};

std::ostream& operator << (std::ostream& out, const T3DPoint& p) {
    p.print(out);
    return out;
}

std::istream& operator >> (std::istream& in, T3DPoint& p) {
    p.scan(in);
    return in;
}

const double T3DPoint::MIN_val = -100;
const double T3DPoint::MAX_val = 100;

