#pragma once
#include <cmath>
#include <iostream>

struct Vec2
{
    double x;
    double y;

    // Constructor
    Vec2(double xP = 0.0, double yP = 0.0);

    // Basic operators
    Vec2 operator+(Vec2 other) const;
    Vec2 operator-(Vec2 other) const;
    Vec2 operator*(Vec2 other) const;
    Vec2 operator/(Vec2 other) const;
    Vec2 operator/(double number) const;

    // Vector operations
    double Magnitude() const;
    Vec2 Normalized() const;
    Vec2 To(Vec2 target) const;
    float DotProduct(Vec2 other) const;

    // Common directions
    static Vec2 Right();
    static Vec2 Left();
    static Vec2 Up();
    static Vec2 Down();
    static Vec2 Zero();
    static Vec2 One();

    // Compound assignment operators
    Vec2& operator=(Vec2 other);
    Vec2& operator+=(Vec2 other);
    Vec2& operator-=(Vec2 other);
    Vec2& operator*=(Vec2 other);
    Vec2& operator/=(Vec2 other);
    Vec2& operator*=(double number);

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
};
