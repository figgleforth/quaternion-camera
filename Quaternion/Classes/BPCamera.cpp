//
//  Camera.cpp
//  oGL
//
//  Created by Bojan Percevic on 11/26/12.
//  Copyright (c) 2012 Bojan Percevic. All rights reserved.
//

#include "BPCamera.h"

#define PI_OVER_180 (3.141459 / 180)

void BPCamera::_update(float pitch, float yaw, float roll, bool multMatrix)
{
    _xRadians = _pitch * PI_OVER_180;
    _yRadians = _yaw * PI_OVER_180;
    _orientation.identity();
    _x.identity();
    _y.identity();
    _z.identity();
    _x.rotateX(-pitch);
    _y.rotateY(-yaw);
    _z.rotateZ(-roll);
    _orientation = _x * _y * _z * _orientation;
    _orientation.toMatrix(_matrix);
    if (multMatrix) {
        glMultMatrixf(this->matrix());
        glTranslatef(-_position.x, _position.y, -_position.z);
    }
}

void BPCamera::_clean()
{
    if (_yaw >= 360) _yaw -= 360;
    else if (_yaw <= 0) _yaw += 360;
    if (_roll >= 360) _roll -= 360;
    else if (_roll <= -360) _roll += 360;
    if (_pitch >= 360) _pitch -= 360;
    else if (_pitch <= -360) _pitch += 360;
}

void BPCamera::update(bool multMatrix)
{
    this->_update(_pitch, _yaw, _roll, multMatrix);
}

void BPCamera::moveForward(float amount)
{
    _position.x += sinf(_yRadians) * amount;
    _position.y += sinf(_xRadians) * amount;
    _position.z -= cosf(_yRadians) * amount;
}

void BPCamera::moveBackward(float amount)
{
    _position.x -= sinf(_yRadians) * amount;
    _position.y -= sinf(_xRadians) * amount;
    _position.z += cosf(_yRadians) * amount;
}

void BPCamera::strafeLeft(float amount)
{
    _position.x -= cosf(_yRadians) * amount;
    _position.z -= sinf(_yRadians) * amount;
}

void BPCamera::strafeRight(float amount)
{
    _position.x += cosf(_yRadians) * amount;
    _position.z += sinf(_yRadians) * amount;
}

void BPCamera::lookUp(float amount)
{
    _pitch -= amount;
    this->_clean();
}

void BPCamera::lookDown(float amount)
{
    _pitch += amount;
    this->_clean();    
}

void BPCamera::lookLeft(float amount)
{
    _yaw -= amount;
    this->_clean();    
}

void BPCamera::lookRight(float amount)
{
    _yaw += amount;
    this->_clean();    
}

void BPCamera::rollLeft(float amount)
{
    _roll -= amount;
    this->_clean();    
}

void BPCamera::rollRight(float amount)
{
    _roll += amount;
    this->_clean();
}

Quaternion BPCamera::orientation()
{
    return _orientation;
}

Vector3f BPCamera::position()
{
    return _position;
}

GLfloat* BPCamera::matrix()
{
    return _matrix;
}