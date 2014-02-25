//
//  Environment.h
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Environment__
#define __MOE__Environment__

// #define GLM_FORCE_RADIANS

#include <iostream>

#include "Mesh.h"
#include "glm/glm.hpp"

class Environment {
    // mesh file
    Mesh *mesh;
    // position
    glm::vec3 pos;
    // scale
    glm::vec3 scl;
    // rotation
    glm::vec3 rot;
    
    // private constructor
    Environment();
    
public:
    // returns a pointer to the Environment singleton
    static Environment *getInstance() {
        static Environment instance;
        return &instance;
    }

    ~Environment();
    
    // load environment
    void loadEnv(const char *mesh, const char *tex);
    // return environment dimensions
    glm::vec3 getDimensions();
    // get environment position
    glm::vec3 getPosition() {
        return pos;
    }
    // get environment scale
    glm::vec3 getScale() {
        return scl;
    }
    // draw environment
    void draw();
};

#endif /* defined(__MOE__Environment__) */
