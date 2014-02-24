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
    pos = {0, -10, 0};
    vel = {0, 0, 0};
    rot = {0, 0, 0};
    aVel = {0, 0, 0};
}

Physics2::~Physics2() {
    
}

void Physics2::update() {
    pos.x = pos.x + vel.x * Clock::getInstance()->getTimeScale();
    pos.y = pos.y + vel.y * Clock::getInstance()->getTimeScale();
    pos.z = pos.z + vel.z * Clock::getInstance()->getTimeScale();
    
    rot.x = rot.x + aVel.x * Clock::getInstance()->getTimeScale();
    rot.y = rot.y + aVel.y * Clock::getInstance()->getTimeScale();
    rot.z = rot.z + aVel.z * Clock::getInstance()->getTimeScale();
}
