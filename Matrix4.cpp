#include "Matrix4.h"
#include <cmath>
#include <iostream>
#define M_PI 3.14159265358979323846
// default constructor, initializes matrix to identity matrix
Matrix4::Matrix4() {
    mdata[0] = 1.0;
    mdata[1] = 0.0;
    mdata[2] = 0.0;
    mdata[3] = 0.0;
    mdata[4] = 0.0;
    mdata[5] = 1.0;
    mdata[6] = 0.0;
    mdata[7] = 0.0;
    mdata[8] = 0.0;
    mdata[9] = 0.0;
    mdata[10] = 1.0;
    mdata[11] = 0.0;
    mdata[12] = 0.0;
    mdata[13] = 0.0;
    mdata[14] = 0.0;
    mdata[15] = 1.0;
}

// constructor with initialization matrix m
Matrix4::Matrix4(double m[]) {
    for (int i = 0; i < 16; i++) {
        mdata[i] = m[i];
    }
}

// static constructor function for translation matrix
Matrix4 Matrix4::Translate(double tx, double ty, double tz) {
    Matrix4 mat;
    mat.mdata[3] = tx;
    mat.mdata[7] = ty;
    mat.mdata[11] = tz;
    return mat;
}

// static constructor function for scale matrix
Matrix4 Matrix4::Scale(double sx, double sy, double sz) {
    Matrix4 mat;
    mat.mdata[0] = sx;
    mat.mdata[5] = sy;
    mat.mdata[10] = sz;
    return mat;
}

// static constructor function for X-axis rotation matrix
Matrix4 Matrix4::RotateX(double angle) {
    double rad = angle * M_PI / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    Matrix4 mat;
    mat.mdata[5] = c;
    mat.mdata[6] = -s;
    mat.mdata[9] = s;
    mat.mdata[10] = c;
    return mat;
}

// static constructor function for Y-axis rotation matrix
Matrix4 Matrix4::RotateY(double angle) {
    double rad = angle * M_PI / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    Matrix4 mat;
    mat.mdata[0] = c;
    mat.mdata[2] = s;
    mat.mdata[8] = -s;
    mat.mdata[10] = c;
    return mat;
}

// static constructor function for Z-axis rotation matrix
Matrix4 Matrix4::RotateZ(double angle) {
    double rad = angle * M_PI / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    Matrix4 mat;
    mat.mdata[0] = c;
    mat.mdata[1] = -s;
    mat.mdata[4] = s;
    mat.mdata[5] = c;
    return mat;
}

// static constructor function for arbitrary-axis rotation matrix
Matrix4 Matrix4::Rotate(double x, double y, double z, double angle) {
    double rad = angle * M_PI / 180.0;
    double c = cos(rad);
    double s = sin(rad);
    double vlen = sqrt(x * x + y * y + z * z);
    double vx = x / vlen;
    double vy = y / vlen;
    double vz = z / vlen;

    Matrix4 rotationMatrix;
    rotationMatrix.mdata[0] = vx * vx * (1 - c) + c;
    rotationMatrix.mdata[1] = vx * vy * (1 - c) - vz * s;
    rotationMatrix.mdata[2] = vx * vz * (1 - c) + vy * s;
    rotationMatrix.mdata[3] = 0;
    rotationMatrix.mdata[4] = vy * vx * (1 - c) + vz * s;
    rotationMatrix.mdata[5] = vy * vy * (1 - c) + c;
    rotationMatrix.mdata[6] = vy * vz * (1 - c) - vx * s;
    rotationMatrix.mdata[7] = 0;
    rotationMatrix.mdata[8] = vz * vx * (1 - c) - vy * s;
    rotationMatrix.mdata[9] = vz * vy * (1 - c) + vx * s;
    rotationMatrix.mdata[10] = vz * vz * (1 - c) + c;
    rotationMatrix.mdata[11] = 0;
    rotationMatrix.mdata[12] = 0;
    rotationMatrix.mdata[13] = 0;
    rotationMatrix.mdata[14] = 0;
    rotationMatrix.mdata[15] = 1;

    return rotationMatrix;
}
// multiply vector v by this matrix
Vector4 Matrix4::mult(Vector4 v)  {
    float x = v.x * mdata[0] + v.y * mdata[1] + v.z * mdata[2] + v.w * mdata[3];
    float y = v.x * mdata[4] + v.y * mdata[5] + v.z * mdata[6] + v.w * mdata[7];
    float z = v.x * mdata[8] + v.y * mdata[9] + v.z * mdata[10] + v.w * mdata[11];
    float w = v.x * mdata[12] + v.y * mdata[13] + v.z * mdata[14] + v.w * mdata[15];
    return Vector4(x, y, z, w);
}

// multiply matrix m by this matrix
Matrix4 Matrix4::mult(Matrix4 m)  {
    Matrix4 result;
    for (int row = 0; row < 4; row++) {
        for (int col = 0; col < 4; col++) {
            double sum = 0.0;
            for (int i = 0; i < 4; i++) {
                sum += mdata[row * 4 + i] * m.mdata[i * 4 + col];
            }
            result.mdata[row * 4 + col] = sum;
        }
    }
    return result;
}

// calculate the determinant
double Matrix4::det() {
    double det = mdata[0] * mdata[5] * mdata[10] * mdata[15] - mdata[0] * mdata[5] * mdata[11] * mdata[14] -
        mdata[0] * mdata[6] * mdata[9] * mdata[15] + mdata[0] * mdata[6] * mdata[9] * mdata[14] + mdata[1] * mdata[6] * mdata[11] * mdata[12] - mdata[1] * mdata[6] * mdata[8] * mdata[15] +
        mdata[1] * mdata[7] * mdata[8] * mdata[14] - mdata[1] * mdata[7] * mdata[10] * mdata[12] - mdata[2] * mdata[5] * mdata[11] * mdata[12] +
        mdata[2] * mdata[5] * mdata[8] * mdata[15] - mdata[2] * mdata[7] * mdata[8] * mdata[13] + mdata[2] * mdata[7] * mdata[9] * mdata[12] +
        mdata[3] * mdata[4] * mdata[9] * mdata[14] - mdata[3] * mdata[4] * mdata[10] * mdata[13] + mdata[3] * mdata[5] * mdata[10] * mdata[12] -
        mdata[3] * mdata[5] * mdata[8] * mdata[14] + mdata[3] * mdata[6] * mdata[8] * mdata[13] - mdata[3] * mdata[6] * mdata[9] * mdata[12];
    return det;
}

void Matrix4::print()
{
     for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << mdata[i * 4 + j] << " ";
        }
        std::cout << std::endl;
    }
}
 
