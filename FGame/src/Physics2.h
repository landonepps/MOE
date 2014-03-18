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
#include "Skybox.h"

class Physics2 {
    // position
    glm::vec3 pos;
    // velocity
    glm::vec3 vel;
    // rotation
    glm::vec3 rot;
    // angular velocity
    glm::vec3 aVel;
    // acceleration
    glm::vec3 acc;
    
    // handle collision with environment
    // void handleEnvCollision(glm::vec4 adjVel);
    
public:
    Physics2();
    ~Physics2();
    
    void update();
    
    // get position
    glm::vec3 getPos() {
        return pos;
    }
    
    // get rotation
    glm::vec3 getRot() {
        return rot;
    }
    
    // set x and z velocity
    void setVel(glm::vec3 newVel) {
        vel = newVel;
    }
    
    // set y velocity
    void setVelY(GLfloat yVel) {
        vel.y = yVel;
    }
    
    // set angular velocity
    void setAVel(glm::vec3 newAVel) {
        aVel = newAVel;
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
    bool checkCollision(glm::vec3 center1, glm::vec3 center2, glm::vec3 d1, glm::vec3 d2);
};

#endif /* defined(__MOE__Physics2__) */
