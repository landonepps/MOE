//
//  Camera.h
//  MOE
//
//  Created by Landon Epps on 2/22/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Camera__
#define __MOE__Camera__

#include <iostream>
#ifdef _MSC_VER
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/GL.h>
#include <GL/GLU.h>
#endif

#include "glm/glm.hpp"

class Camera {
    glm::vec3 pos;
    glm::vec3 rot;
    GLfloat fov, aspect, zNear, zFar;
    
public:
    Camera();
    ~Camera();
    
    void multMatrix();
    void setPosition(glm::vec3 newPos);
    void setRotation(glm::vec3 newRot);
    void setFov(GLfloat newFov);
    void setAspect(GLfloat newAspect);
    void setZNear(GLfloat newZNear);
    void setZFar(GLfloat newZFar);
};

#endif /* defined(__MOE__Camera__) */
