/*******************************************************************************
 *
 * Author:      Jeremy Stark
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Spring 2014
 * Date:        2/22/2014
 *
 * Handles the images, animation, and collision for game characters
 *
 ******************************************************************************/

#include "Physics.h"

#define XACCELRATE  1
#define YACCELRATE  2
#define ZACCELRATE  1

Physics::Physics() {
    /* Velocity values */
    xVel = 0;
    yVel = 0;
    zVel = 0;
    
    /* Acceleration values */
    xAccel = 0;
    yAccel = 0;
    zAccel = 0;
    
    airborne = false;
}


Physics::~Physics() {
    
}

void Physics::update(Clock *clock) {
    xVel += xAccel * clock->getTimeScale();
    zVel += zAccel * clock->getTimeScale();
    
    yVel += yAccel * clock->getTimeScale();
    if(airborne) {
        yVel -= GRAVITY * clock->getTimeScale();
    }
}

void Physics::moveUp() {
    yAccel += YACCELRATE;
}

void Physics::moveDown() {
    yAccel -= YACCELRATE;
}

void Physics::moveLeft() {
    xAccel -= XACCELRATE;
}

void Physics::moveRight() {
    xAccel += XACCELRATE;
}

void Physics::moveForward() {
    zAccel += ZACCELRATE;
}

void Physics::moveBack() {
    zAccel -= ZACCELRATE;
}

void Physics::halt() {
    xVel = zVel = yVel = 0;
}