#include "Vector4.h"
#include <cmath>
#include <iostream>

Vector4::Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}

Vector4::Vector4(float x, float y, float z) : x(x), y(y), z(z), w(0.0f) {}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

Vector4::Vector4(const Vector4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

float Vector4::magnitude() const {
    return sqrt(x * x + y * y + z * z + w * w);
}

float Vector4::dot(const Vector4& v) const {
    return x * v.x + y * v.y + z * v.z + w * v.w;
}

Vector4 Vector4::cross(const Vector4& v) const {
    return Vector4(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x, 0.0f);
}

void Vector4::normalize() {
    float mag = magnitude();
    if (mag > 0.0f) {
        x /= mag;
        y /= mag;
        z /= mag;
        w /= mag;
    }
}
void Vector4::print() 
{
    std::cout << x << " " << y << " " << z << " " << w<< std::endl;
}
