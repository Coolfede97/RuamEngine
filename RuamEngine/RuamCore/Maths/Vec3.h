#pragma once
#include <cmath>
#include <iostream>

class Vec3
{
public:
	double x;
	double y;

	Vec3(double xP = 0.0, double yP = 0.0);

	Vec3 operator+(Vec3 other) const;
	Vec3 operator-(Vec3 other) const;
	Vec3 operator*(Vec3 other) const;
	Vec3 operator/(Vec3 other) const;

	Vec3 operator/(double number) const;

	double magnitude();
	Vec3 normalized();
	Vec3 To(Vec3 target);
	float DotProduct(Vec3 other);

	static const Vec3 Right();
	static const Vec3 Left();
	static const Vec3 Up();
	static const Vec3 Down();
	static const Vec3 Zero();
	static const Vec3 One();

	Vec3 operator=(Vec3 other);
	Vec3 operator+=(Vec3 other);
	Vec3 operator-=(Vec3 other);
	Vec3 operator*=(Vec3 other);
	Vec3 operator/=(Vec3 other);
	Vec3 operator*=(double number);

	friend std::ostream& operator<<(std::ostream& os, const Vec3& v);
};