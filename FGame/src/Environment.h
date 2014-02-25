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
    Mesh *mesh;
    glm::vec3 pos;
    glm::vec3 scl;
    glm::vec3 rot;
    
    Environment();
    
public:
    static Environment *getInstance() {
        static Environment instance;
        return &instance;
    }

    ~Environment();
    
    void loadEnv(const char *mesh, const char *tex);
    glm::vec3 getDimensions();
    glm::vec3 getPosition() {
        return pos;
    }
    glm::vec3 getScale() {
        return scl;
    }
    void draw();
};

#endif /* defined(__MOE__Environment__) */
