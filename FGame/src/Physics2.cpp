//
//  Physics2.cpp
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Physics2.h"
#include "Clock.h"
#include "glm/gtc/matrix_transform.hpp"

Physics2::Physics2() {
    pos = glm::vec3(0, -25, 0);
    vel = glm::vec3(0, 0, 0);
}

Physics2::~Physics2() {
    
}

void Physics2::update() {
    // adjust velocity for player rotation
    glm::mat4 rotMat = glm::rotate(glm::mat4(), -rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
    glm::vec4 adjVel = rotMat * glm::vec4(vel.x, vel.y, vel.z, 0);
    
    // update position based on velocity
    pos.x = pos.x + adjVel.x * Clock::getInstance()->getDeltaTime();
    pos.y = pos.y + adjVel.y * Clock::getInstance()->getDeltaTime();
    pos.z = pos.z + adjVel.z * Clock::getInstance()->getDeltaTime();
    rot.x = rot.x + aVel.x * Clock::getInstance()->getDeltaTime();
    rot.y = rot.y + aVel.y * Clock::getInstance()->getDeltaTime();
    rot.z = rot.z + aVel.z * Clock::getInstance()->getDeltaTime();
}

/***********************************************************************
* checkCollision: checks the collision between two objects based on their
*                   center point and dimensions. Returns true if a collision
*                   has occured.
*
* center1: center point of the first object
* center2: center point of the second object
* d1: dimensions of the first object
* d2: dimensions of the second object
*
* returns:   bool
***********************************************************************/
bool Physics2::checkCollision(glm::vec3 center1, glm::vec3 center2, glm::vec3 d1, glm::vec3 d2){
    bool collided = false;

    if (
        -(center1.z - d1.z / 2) <= center2.z + d2.z / 2 && center1.x + d1.x / 2 >= center2.x - d2.x / 2 &&
        (center1.x - d1.x / 2) <= center2.x + d2.x / 2 && -(center1.z + d1.z / 2) >= center2.z - d2.z / 2 &&
        -(center1.y - d1.y / 2) <= center2.y + d2.y / 2 && -(center1.y + d1.y / 2) >= center2.y - d2.y / 2
       )
    {
        collided = true;
    }

    return collided;
}
