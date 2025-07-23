#include "Vec3.h"

Vec3::Vec3(double xP, double yP)
{
	x = xP;
	y = yP;
}

Vec3 Vec3::operator+(Vec3 other) const
{
	return Vec3(x + other.x, y + other.y);
}

Vec3 Vec3::operator-(Vec3 other) const
{
	return Vec3(x - other.x, y - other.y);
}

Vec3 Vec3::operator*(Vec3 other) const
{
	return Vec3(x * other.x, y * other.y);
}

Vec3 Vec3::operator/(Vec3 other) const
{
	return Vec3(x / other.x, y / other.y);
}

Vec3 Vec3::operator/(double number) const
{
	return Vec3(x / number, y / number);
}

double Vec3::magnitude()
{
	return sqrt(x * x + y * y);
}

Vec3 Vec3::normalized()
{
	double mag = magnitude();
	return (mag != 0) ? Vec3(x / mag, y / mag) : Zero();
}

Vec3 Vec3::To(Vec3 target)
{
	Vec3 thisVector(x, y);
	return (target - thisVector);
}

float Vec3::DotProduct(Vec3 other)
{
	Vec3 thisNormalized = Vec3(x, y).normalized();
	Vec3 otherNormalized = Vec3(other.x, other.y).normalized();
	return (thisNormalized.x * otherNormalized.x + thisNormalized.y * otherNormalized.y);
}

const Vec3 Vec3::Right() { return Vec3(1, 0); }
const Vec3 Vec3::Left() { return Vec3(-1, 0); }
const Vec3 Vec3::Up() { return Vec3(0, 1); }
const Vec3 Vec3::Down() { return Vec3(0, -1); }
const Vec3 Vec3::Zero() { return Vec3(0, 0); }
const Vec3 Vec3::One() { return Vec3(1, 1); }

Vec3 Vec3::operator=(Vec3 other)
{
	this->x = other.x;
	this->y = other.y;
	return *this;
}

Vec3 Vec3::operator+=(Vec3 other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vec3 Vec3::operator-=(Vec3 other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vec3 Vec3::operator*=(Vec3 other)
{
	this->x *= other.x;
	this->y *= other.y;
	return *this;
}

Vec3 Vec3::operator/=(Vec3 other)
{
	this->x /= other.x;
	this->y /= other.y;
	return *this;
}

Vec3 Vec3::operator*=(double number)
{
	this->x *= number;
	this->y *= number;
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
	os << "(" << v.x << ", " << v.y << ")";
	return os;
}