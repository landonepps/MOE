//
//  Physics.h
//  MOE
//
//  Created by Jeremy Stark on 2/22/14.
//  Copyright (c) 2014 Jeremy Stark. All rights reserved.
//

#ifndef __MOE__Physics__
#define __MOE__Physics__

#include <iostream>
#ifdef _MSC_VER
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/GL.h>
#include <GL/GLU.h>
#endif

#include "glm/glm.hpp"
#include "Clock.h"

class Physics {
    
    /* Needs fine tuning */
    const static int GRAVITY = 1;
    
    /* Rates of acceleration for movement */
    const int XACCELRATE = 1;
    const int YACCELRATE = 2;
    const int ZACCELRATE = 1;
    
    /* Velocity values */
    int xVel;
    int yVel;
    int zVel;
    
    /* Acceleration values */
    int xAccel;
    int yAccel;
    int zAccel;
    
    bool airborne;
    
public:
    Physics();
    ~Physics();
    
    void update(Clock* clock);
    
    void moveUp();
    void moveDown();
    
    void moveLeft();
    void moveRight();
    
    void moveForward();
    void moveBack();
    
    void halt();
};

#endif /* defined(__MOE__Physics__) */
