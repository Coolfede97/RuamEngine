#include "Vec3.h"
#include <cmath> // Para std::sqrt

Vec3::Vec3(float xP, float yP, float zP) : x(xP), y(yP), z(zP) {}

Vec3 Vec3::operator+(Vec3 other) const {
    return Vec3(x + other.x, y + other.y, z + other.z);
}

Vec3 Vec3::operator-(Vec3 other) const {
    return Vec3(x - other.x, y - other.y, z - other.z);
}

Vec3 Vec3::operator*(Vec3 other) const {
    return Vec3(x * other.x, y * other.y, z * other.z);
}

Vec3 Vec3::operator/(Vec3 other) const {
    return Vec3(x / other.x, y / other.y, z / other.z);
}

Vec3 Vec3::operator/(float number) const {
    return Vec3(x / number, y / number, z / number);
}

float Vec3::Magnitude() const {
    return std::sqrt(x * x + y * y + z * z);
}

Vec3 Vec3::Normalized() const {
    float mag = Magnitude();
    return (mag != 0) ? Vec3(x / mag, y / mag, z / mag) : Zero();
}

Vec3 Vec3::To(Vec3 target) const {
    return target - *this;
}

float Vec3::DotProduct(Vec3 other) const {
    Vec3 a = Normalized();
    Vec3 b = other.Normalized();
    return static_cast<float>(a.x * b.x + a.y * b.y + a.z * b.z);
}

Vec3 Vec3::Right() { return Vec3(1, 0, 0); }
Vec3 Vec3::Left() { return Vec3(-1, 0, 0); }
Vec3 Vec3::Up() { return Vec3(0, 1, 0); }
Vec3 Vec3::Down() { return Vec3(0, -1, 0); }
Vec3 Vec3::Forward() { return Vec3(0, 0, 1); }
Vec3 Vec3::Backward() { return Vec3(0, 0, -1); }
Vec3 Vec3::Zero() { return Vec3(0, 0, 0); }
Vec3 Vec3::One() { return Vec3(1, 1, 1); }

Vec3& Vec3::operator=(Vec3 other) {
    x = other.x;
    y = other.y;
    z = other.z;
    return *this;
}

Vec3& Vec3::operator+=(Vec3 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    return *this;
}

Vec3& Vec3::operator-=(Vec3 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    return *this;
}

Vec3& Vec3::operator*=(Vec3 other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    return *this;
}

Vec3& Vec3::operator/=(Vec3 other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    return *this;
}

Vec3& Vec3::operator*=(float number) {
    x *= number;
    y *= number;
    z *= number;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Vec3& v) {
    os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}