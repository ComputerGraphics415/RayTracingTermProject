#include <iostream>
#include "Vector4.h"
#include "Matrix4.h"

int main()
{
    // Testing Vector4 class
    Vector4 v1(1.0f, 2.0f, 3.0f, 0.0f);
    Vector4 v2(4.0f, 5.0f, 6.0f, 0.0f);
    std::cout << "v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ", " << v1.w << ")" << std::endl;
    std::cout << "v2: (" << v2.x << ", " << v2.y << ", " << v2.z << ", " << v2.w << ")" << std::endl;

    float dot_product = v1.dot(v2);
    std::cout << "Dot product of v1 and v2: " << dot_product << std::endl;

    Vector4 cross_product = v1.cross(v2);
    std::cout << "Cross product of v1 and v2: (" << cross_product.x << ", " << cross_product.y << ", " << cross_product.z << ", " << cross_product.w << ")" << std::endl;

    float magnitude_v1 = v1.magnitude();
    std::cout << "Magnitude of v1: " << magnitude_v1 << std::endl;

    v1.normalize();
    std::cout << "Normalized v1: (" << v1.x << ", " << v1.y << ", " << v1.z << ", " << v1.w << ")" << std::endl;

    // Testing Matrix4 class
    Matrix4 m1;
    std::cout << "m1: " << std::endl;
    m1.print();

    double mdata[16] = { 1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f, 13.0f, 14.0f, 15.0f, 16.0f };
    Matrix4 m2(mdata);
    std::cout << "m2: " << std::endl;
    m2.print();

    Matrix4 translation_matrix = Matrix4::Translate(1.0f, 2.0f, 3.0f);
    std::cout << "Translation Matrix: " << std::endl;
    translation_matrix.print();

    Matrix4 scale_matrix = Matrix4::Scale(2.0f, 3.0f, 4.0f);
    std::cout << "Scale Matrix: " << std::endl;
    scale_matrix.print();

    Matrix4 rotation_x_matrix = Matrix4::RotateX(45.0f);
    std::cout << "Rotation Matrix along X: " << std::endl;
    rotation_x_matrix.print();

    Matrix4 rotation_y_matrix = Matrix4::RotateY(60.0f);
    std::cout << "Rotation Matrix along Y: " << std::endl;
    rotation_y_matrix.print();

    Matrix4 rotation_z_matrix = Matrix4::RotateZ(30.0f);
    std::cout << "Rotation Matrix along Z: " << std::endl;
    rotation_z_matrix.print();

    Matrix4 rotation_matrix = Matrix4::Rotate(1.0f, 2.0f, 3.0f, 30);
    std::cout << "Rotation Matrix : " << std::endl;
    rotation_matrix.print();

    Matrix4 m;
    Vector4 test(1, 2, 3, 1);
    Vector4 vector_mult = m.mult(test);
    std::cout << "Vector Multiplication : " << std::endl;
    vector_mult.print();

    Matrix4 m4(mdata);
    Matrix4 m_m4 = m.mult(m4);
    std::cout << "Matrix Multiplication : " << std::endl;
    m_m4.print();

    Matrix4 det(mdata);
    std::cout << "Determinant : " << std::endl;
    std::cout << det.det();

}