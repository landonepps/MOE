//
//  Physics2.h
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Physics2__
#define __MOE__Physics2__

#include <iostream>
#include "glm/glm.hpp"

class Physics2 {
    glm::vec3 pos;
    glm::vec3 vel;
    glm::vec3 rot;
    glm::vec3 aVel;
    glm::vec3 acc;
    
public:
    Physics2();
    ~Physics2();
    
    void update();
    
    glm::vec3 getPos() {
        return pos;
    }
    
    glm::vec3 getRot() {
        return rot;
    }
    
    void setVel(glm::vec3 newVel) {
        vel = newVel;
    }
    
    void setAVel(glm::vec3 newAVel) {
        aVel = newAVel;
    }
};

#endif /* defined(__MOE__Physics2__) */
