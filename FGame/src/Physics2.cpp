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
