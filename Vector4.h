#ifndef VECTOR4_H
#define VECTOR4_H

class Vector4 {
public:
    float x, y, z, w;

    Vector4();
    Vector4(float x, float y, float z);
    Vector4(float x, float y, float z, float w);
    Vector4(const Vector4& v);

    float magnitude() const;
    float dot(const Vector4& v) const;
    Vector4 cross(const Vector4& v) const;
    void normalize();
    void print();
};

#endif
