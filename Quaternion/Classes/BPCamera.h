//
//  Camera.h
//  oGL
//
//  Created by Bojan Percevic on 11/26/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#ifndef __oGL__Camera__
#define __oGL__Camera__

#include <iostream>
#include "Quaternion.h"
#include "Vector3f.h"

class BPCamera {
private:
    Quaternion _orientation;
    Quaternion _x;
    Quaternion _y;
    Quaternion _z;
    GLfloat _pitch;
    GLfloat _yaw;
    GLfloat _roll;
    Vector3f _position;
    GLfloat _matrix[16];
    float _xRadians;
    float _yRadians;
    
    void _update(float pitch, float yaw, float roll, bool multMatrix);
    void _clean();
public:
    ~BPCamera() {};
    BPCamera()
    {
        _orientation = Quaternion();
        _x = Quaternion();
        _y = Quaternion();
        _z = Quaternion();
        _position.x = _position.y = _position.z = 0;
    };
    
    void update(bool multMatrix);
    
    void moveForward(float amount);
    void moveBackward(float amount);
    void strafeLeft(float amount);
    void strafeRight(float amount);
    
    void lookUp(float amount);
    void lookDown(float amount);
    void lookLeft(float amount);
    void lookRight(float amount);
    void rollLeft(float amount);
    void rollRight(float amount);
    
    Quaternion orientation();
    Vector3f position();
    GLfloat* matrix();
};

#endif /* defined(__oGL__Camera__) */
