/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * Handles the camera
 *
 ******************************************************************************/
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
    // position
    glm::vec3 pos;
    // rotation
    glm::vec3 rot;
    // field of view, aspect ration, min draw, max draw
    GLfloat fov, aspect, zNear, zFar;
    
public:
    Camera();
    ~Camera();
    
    // multiply camera matrix using glMulMatrix
    void multMatrix();
    // set camera position
    void setPosition(glm::vec3 newPos);
    // set camera rotation
    void setRotation(glm::vec3 newRot);
    // set camera fov
    void setFov(GLfloat newFov);
    // set camera apsect ratio
    void setAspect(GLfloat newAspect);
    // set minimum z draw
    void setZNear(GLfloat newZNear);
    // set max z draw
    void setZFar(GLfloat newZFar);
};

#endif /* defined(__MOE__Camera__) */
