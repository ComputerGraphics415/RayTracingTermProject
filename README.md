# RayTracingTermProject
week1
Assignment:
n this assignment, you will implement Vector and Matrix classes that you will use throughout
the semester. You need to test them as well. You can use any programming language. It would 
be preferable to use an object oriented approach.
Submit your classes, test file, and the output of your test (a text file) in a zip file.
Vector4 class:
This is the 
Attributes: 
 float x, y, z, w (you can keep them as a float array of size 4)
Methods: 
 necessary constructors: Vector4(), Vector4(x,y,z), Vector4(x,y,z,w), Vector4(v)
 float magnitude(): returns magnitude of the vector. Sometimes we refer to it as length but 
magnitude is the more correct term
 float dot(v): calculates dot product of this vector with v and returns it
 Vector4 cross(v): calculates cross product of this vector with v and returns it
 void normalize(): normalizes this vectors, i.e., magnitude becomes 1 
Matrix4 class:
Attributes:
 mdata: 16 values should be kept here (an array of 16 or a double array of 4 by 4)
Methods:
 necessary constructors: Matrix4(), Matrix4(m)
 static constructor functions: 
o Matrix4 Translate(tx, ty, tz): returns the 4x4 translation matrix
o Matrix4 Scale(sx, sy, sz): returns the 4x4 scale matrix
o Matrix4 RotateX(angle): returns the 4x4 matrix for rotation by angle on x
o Matrix4 RotateY(angle): returns the 4x4 matrix for rotation by angle on y
o Matrix4 RotateZ(angle): returns the 4x4 matrix for rotation by angle on z
o Matrix4 Rotate(x, y, z, angle): returns the 4x4 matrix for rotation around vector(x,y,z) by 
angle
 Vector4 mult(v): multiplies this with v and returns the result
 Matrix4 mult(m): multiplies this with m and returns the result
 float det(): calculates the determinant and returns it
Test class:
Here you should test all the methods you implemented
