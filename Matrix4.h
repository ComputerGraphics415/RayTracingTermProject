#ifndef MATRIX4_H
#define MATRIX4_H

#include "Vector4.h"

class Matrix4 {
public:
    double mdata[16];

    Matrix4();
    Matrix4(double m[]);  

    static Matrix4 Translate(double tx, double ty, double tz);
    static Matrix4 Scale(double sx, double sy, double sz);
    static Matrix4 RotateX(double angle);
    static Matrix4 RotateY(double angle);
    static Matrix4 RotateZ(double angle);
    static Matrix4 Rotate(double x, double y, double z, double angle);

    Vector4 mult(Vector4 v);
    Matrix4 mult(Matrix4 m);


    double det() ;
    void print();
};

#endif // MATRIX4_H
