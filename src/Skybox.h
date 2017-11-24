//
//  Skybox.h
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Skybox__
#define __MOE__Skybox__

// #define GLM_FORCE_RADIANS

#include <iostream>

#include "Mesh.h"
#include "glm/glm.hpp"

class Skybox {
    // mesh file
    Mesh *mesh;
    // position
    glm::vec3 pos;
    // scale
    glm::vec3 scl;
    // rotation
    glm::vec3 rot;
    
    // private constructor
    Skybox();
    
public:
    // returns a pointer to the Skybox singleton
    static Skybox *getInstance() {
        static Skybox instance;
        return &instance;
    }
    
    ~Skybox();
    
    // load skybox
    void loadSky(const char *mesh, const char *tex);
    // return skybox dimensions
    glm::vec3 getDimensions();
    // get skybox position
    glm::vec3 getPosition() {
        return pos;
    }
    // get skybox scale
    glm::vec3 getScale() {
        return scl;
    }
    // update skybox
    void setPos(glm::vec3 newPos) {
        pos = newPos;
    }
    // draw skybox
    void draw();
};

#endif /* defined(__MOE__Skybox__) */
