//
//  Quaternion.cpp
//  oGL
//
//  Created by Bojan Percevic on 11/26/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#include "Quaternion.h"
#include <math.h>

#define PI_OVER_180 (3.141459 / 180)

void Quaternion::identity()
{
    x = y = z = 0;
    w = 1;
}

Quaternion Quaternion::normalize()
{
    float length = sqrtf( (x*x) + (y*y) + (z*z) + (w*w) );
    Quaternion *q = new Quaternion(x/=length, y/=length, z/=length, w/=length);
    return *q;
}

Quaternion Quaternion::conjugate()
{
    Quaternion *q = new Quaternion(-x, -y, -z, -w);
    return *q;
}

Quaternion Quaternion::operator* (Quaternion OtherQuat)
{
    float W = (OtherQuat.w * w) - (OtherQuat.x * x) - (OtherQuat.y * y) - (OtherQuat.z * z);
    float X = (OtherQuat.w * x) + (OtherQuat.x * w) + (OtherQuat.y * z) - (OtherQuat.z * y);
    float Y = (OtherQuat.w * y) + (OtherQuat.y * w) + (OtherQuat.z * x) - (OtherQuat.x * z);
    float Z = (OtherQuat.w * z) + (OtherQuat.z * w) + (OtherQuat.x * y) - (OtherQuat.y * x);
    Quaternion NewQuat = Quaternion();
    NewQuat.w = W;
    NewQuat.x = X;
    NewQuat.y = Y;
    NewQuat.z = Z;
    return NewQuat;
}

void Quaternion::multiply(Quaternion q)
{
    Quaternion *b = new Quaternion(q.x, q.y, q.z, q.w);
    x = w*b->x + x*b->w + y*b->z + z*b->y;
    y = w*b->y - x*b->z + y*b->w + z*b->x;
    z = w*b->z + x*b->y - y*b->x + z*b->w;
    w = w*b->w - x*b->x - y*b->y - z*b->z;
}

void Quaternion::rotateX(float degrees)
{
    float rad = ( degrees * PI_OVER_180 ) / 2;
    float nx = 1 * sinf(rad);
    float ny = 0 * sinf(rad);
    float nz = 0 * sinf(rad);
    float nw = cosf(rad);
    Quaternion *newQuat = new Quaternion(nx,  ny, nz, nw);
    Quaternion *oldSelf = new Quaternion(x, y, z, w);
    newQuat->multiply(*oldSelf);
    multiply(*newQuat);
    x = newQuat->x;
    y = newQuat->y;
    z = newQuat->z;
    w = newQuat->w;
}

void Quaternion::rotateY(float degrees)
{
    float rad = ( degrees * PI_OVER_180 ) / 2;
    float nx = 0 * sinf(rad);
    float ny = 1 * sinf(rad);
    float nz = 0 * sinf(rad);
    float nw = cosf(rad);
    Quaternion *newQuat = new Quaternion(nx,  ny, nz, nw);
    Quaternion *oldSelf = new Quaternion(x, y, z, w);
    newQuat->multiply(*oldSelf);
    multiply(*newQuat);
    x = newQuat->x;
    y = newQuat->y;
    z = newQuat->z;
    w = newQuat->w;
}

void Quaternion::rotateZ(float degrees)
{
    float rad = ( degrees * PI_OVER_180 ) / 2;
    float nx = 0 * sinf(rad);
    float ny = 0 * sinf(rad);
    float nz = 1 * sinf(rad);
    float nw = cosf(rad);
    Quaternion *newQuat = new Quaternion(nx,  ny, nz, nw);
    Quaternion *oldSelf = new Quaternion(x, y, z, w);
    newQuat->multiply(*oldSelf);
    multiply(*newQuat);
    x = newQuat->x;
    y = newQuat->y;
    z = newQuat->z;
    w = newQuat->w;
}

GLfloat* Quaternion::matrix()
{
    return 0;
}

void Quaternion::toMatrix(GLfloat *matrix)
{
    GLfloat xx = x*x;
    GLfloat xy = x*y;
    GLfloat xz = x*z;
    GLfloat xw = x*w;
    GLfloat yy = y*y;
    GLfloat yz = y*z;
    GLfloat yw = y*w;
    GLfloat zz = z*z;
    GLfloat zw = z*w;
    
    matrix[0]  = 1 - 2 * ( yy + zz );
    matrix[1]  =     2 * ( xy - zw );
    matrix[2]  =     2 * ( xz + yw );
    
    matrix[4]  =     2 * ( xy + zw );
    matrix[5]  = 1 - 2 * ( xx + zz );
    matrix[6]  =     2 * ( yz - xw );
    
    matrix[8]  =     2 * ( xz - yw );
    matrix[9]  =     2 * ( yz + xw );
    matrix[10] = 1 - 2 * ( xx + yy );
    
    matrix[3]  = matrix[7] = matrix[11] = matrix[12] = matrix[13] = matrix[14] = 0;
    matrix[15] = 1;
    
}
