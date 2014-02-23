/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      22-Feb-2014
*
* Treasure class
*******************************************************************************/

#ifndef TREASURE_H_
#define TREASURE_H_

#include <string>
#include <sstream>
#ifdef _MSC_VER
#include <SDL_ttf.h>
#else
#ifdef __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif
#endif

#include "PropElement.h"
#include "Mesh.h"
#include "glm/glm.hpp"

class Treasure : public PropElement{
private:
    Mesh *theMesh;
    glm::vec3 position;
    glm::vec3 scale;
    bool rotate, clockwise, bob, reached;
    GLfloat bobSpeed, bobMax, bobMin;
    GLfloat rotateAngle, rotateSpeed;
public:
    Treasure();
    Treasure(int);
    ~Treasure();
    void setup(char const* filename, char const* texname);
    void setLocation(GLfloat x, GLfloat y, GLfloat z);
    void setScale(GLfloat sX, GLfloat sY, GLfloat sZ);
    void setRotate(bool rotateSet, bool clockwise, GLfloat speed = 1);
    void setBob(bool bobSet, GLfloat speed = 1, GLfloat bobMax = 20, GLfloat bobMin = 20);
    void toggleBob();
    void toggleClockwise();
    void draw();
    glm::vec3 getPosition();
};

#endif
