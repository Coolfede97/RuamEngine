#pragma once
#include <cmath>
#include <iostream>

struct Vec3
{
    double x;
    double y;
    double z;

    // Constructor
    Vec3(double xP = 0.0f, double yP = 0.0f, double zP = 0.0f);

    // Basic operators
    Vec3 operator+(Vec3 other) const;
    Vec3 operator-(Vec3 other) const;
    Vec3 operator*(Vec3 other) const;
    Vec3 operator/(Vec3 other) const;
    Vec3 operator/(double number) const;

	// Vector operations
    double Magnitude() const;
    Vec3 Normalized() const;
    Vec3 To(Vec3 target) const;
    float DotProduct(Vec3 other) const;

    // Common directions
    static Vec3 Right();
    static Vec3 Left();
    static Vec3 Up();
    static Vec3 Down();
    static Vec3 Forward();
	static Vec3 Backward();
    static Vec3 Zero();
    static Vec3 One();

	// Compound assignment operators
    Vec3& operator=(Vec3 other);
    Vec3& operator+=(Vec3 other);
    Vec3& operator-=(Vec3 other);
    Vec3& operator*=(Vec3 other);
    Vec3& operator/=(Vec3 other);
    Vec3& operator*=(double number);

    // Output
    friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};
