//
//  Quaternion.h
//  oGL
//
//  Created by Bojan Percevic on 11/26/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#ifndef __oGL__Quaternion__
#define __oGL__Quaternion__

#include <iostream>
#include "Vector3f.h"
#include <GLUT/GLUT.h>
#include <math.h>

class Quaternion {
private:

    
public:
    float x;
    float y;
    float z;
    float w;
    ~Quaternion() {};
    
    Quaternion()
    {
        w = 1;
        x = 0;
        y = 0;
        z = 0;
    };

    Quaternion(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
    
    void identity();
    Quaternion normalize();
    Quaternion conjugate();
    Quaternion operator*(const Quaternion q);
    
    void rotateX(float degrees);
    void rotateY(float degrees);
    void rotateZ(float degrees);
    GLfloat* matrix();
    void toMatrix(GLfloat *matrix);
    
    void multiply(Quaternion q);


};

#endif /* defined(__oGL__Quaternion__) */
