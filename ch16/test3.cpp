#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace::std;

class Vector3D
{
  public:

  float x, y, z;

  Vector3D() = default;
  Vector3D(float a, float b, float c)
  : x(a), y(b), z(c) {}

  float& operator [] (int i) { return ( (&x)[0+i] ); } 

  const float& operator [] (int i) const { return ( (&x)[i] ); }

  Vector3D& operator*= (float s)
  {
    x*=s; 
    y*=s;
    z*=s;
    return *this;
  }

  Vector3D& operator /= (float s)
  {
    s=1.0F / s;
    x*=s;
    y*=s;
    z*=s;
    return *this;
  }  

  Vector3D& operator += (const Vector3D& v)
  {
    x+=v.x;
    y+=v.y;
    z+=v.z;
    return *this;
  }

    Vector3D& operator -= (const Vector3D& v)
  {
    x-=v.x;
    y-=v.y;
    z-=v.z;
    return *this;
  }
};

inline Vector3D operator + (const Vector3D& a, const Vector3D& b)
{
  return (Vector3D(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline Vector3D operator - (const Vector3D& a, const Vector3D& b)
{
  return (Vector3D(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline Vector3D operator * (const Vector3D&v, float s)
{
  return (Vector3D(v.x*s, v.y*s, v.z*s));
}

inline Vector3D operator / (const Vector3D&v, float s)
{
  s= 1.0F/s;
  return (Vector3D(v.x*s, v.y*s, v.z*s));
}

inline Vector3D operator - (const Vector3D& v)
{
  return (Vector3D(-v.x, -v.y, -v.z));
}

inline float Magnitude (const Vector3D& v)
{
  return (sqrt (v.x*v.x + v.y*v.y + v.z*v.z));
}

inline Vector3D Normalize (const Vector3D& v)
{
  return (v / Magnitude(v));
}

class Matrix3D
{
  private:
  float n[3][3];

  public:
  Matrix3D() = default;

  Matrix3D(float n00, float n01, float n02,
           float n10, float n11, float n12,
           float n20, float n21, float n22)
           {
             n[0][0] = n00; n[0][1] = n01; n[0][2] = n02;
             n[1][0] = n10; n[1][1] = n11; n[1][2] = n12;
             n[2][0] = n20; n[2][1] = n21; n[2][2] = n22;
            }
  
  Matrix3D (const Vector3D& a, const Vector3D& b, const Vector3D& c)
  {
    n[0][0] = a.x; n[0][1] = a.y; n[0][2] = a.z;
    n[1][0] = b.x; n[1][1] = b.y; n[1][2] = b.z;
    n[2][0] = c.x; n[2][1] = c.y; n[2][2] = c.z;
  }

  float & operator () (int i, int j) { return n[j][i]; }
  const float & operator () (int i, int j) const { return n[j][i]; }

  const Vector3D& operator [] (int j) const { return  *reinterpret_cast<const Vector3D *>(n[j]) ; }
};

Matrix3D operator *(const Matrix3D& A, const Matrix3D& B)
{
return Matrix3D(A(0,0) * B(0,0) + A(0, 1) * B(1, 0) + A(0, 2) * B(2,0),
                A(0,0) * B(0,1) + A(0, 1) * B(1, 1) + A(0, 2) * B(2,1), 
                A(0,0) * B(0,2) + A(0, 1) * B(1, 2) + A(0, 2) * B(2,2), 
                A(1,0) * B(0,0) + A(1, 1) * B(1, 0) + A(1, 2) * B(2,0), 
                A(1,0) * B(0,1) + A(1, 1) * B(1, 1) + A(1, 2) * B(2,1),
                A(1,0) * B(0,2) + A(1, 1) * B(1, 2) + A(1, 2) * B(2,2), 
                A(2,0) * B(0,0) + A(2, 1) * B(1, 0) + A(2, 2) * B(2,0),
                A(2,0) * B(0,1) + A(2, 1) * B(1, 1) + A(2, 2) * B(2,1),
                A(2,0) * B(0,2) + A(2, 1) * B(1, 2) + A(2, 2) * B(2,2));
}

Vector3D operator *(const Matrix3D& M, const Vector3D& v)
{
  return Vector3D( M(0,0) * v.x + M(0,1) * v.y + M(0,2) * v.z, 
                   M(1,0) * v.x + M(1,1) * v.y + M(1,2) * v.z, 
                   M(2,0) * v.x + M(2,1) * v.y + M(2,2) * v.z);
}

 
int main ()
{
 Vector3D v1 (10.0f,20.0f,30.0f), v2 (40.0f, 50.0f, 60.0f), v3 (70.0f, 80.0f, 90.0f);
 Matrix3D m1 (v1, v2, v3), m2(v3,v1,v2);
Vector3D v4 (1,1,1);
 auto result = m1 * v4;
 auto result2 = m1*m2;

 return 0;
}



