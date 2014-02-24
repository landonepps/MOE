//
//  Physics2.cpp
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Physics2.h"
#include "Clock.h"

Physics2::Physics2() {
    pos = glm::vec3(0, -10, 0);
    vel = glm::vec3(0, 0, 0);
}

Physics2::~Physics2() {
    
}

void Physics2::update() {
    pos.x = pos.x + vel.x * Clock::getInstance()->getElapsedTime();
    pos.y = pos.y + vel.y * Clock::getInstance()->getElapsedTime();
    pos.z = pos.z + vel.z * Clock::getInstance()->getElapsedTime();
}
