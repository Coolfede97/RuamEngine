#pragma once
#include <cmath>
#include <iostream>

struct Vec2
{
    float x;
    float y;

    // Constructor
    Vec2(float xP = 0.0, float yP = 0.0);

    // Basic operators
    Vec2 operator+(Vec2 other) const;
    Vec2 operator-(Vec2 other) const;
    Vec2 operator*(Vec2 other) const;
    Vec2 operator/(Vec2 other) const;
    Vec2 operator/(float number) const;

    // Vector operations
    float Magnitude() const;
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
    Vec2& operator*=(float number);

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Vec2& v);
};
