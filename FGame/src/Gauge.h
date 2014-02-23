/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      8-Feb-2014
*
* Gauge HUD class
*******************************************************************************/

#ifndef GAUGE_H_
#define GAUGE_H_

#include "HUDelement.h"
#include "glm/glm.hpp"

class Gauge : public HUDelement{
private:
    GLfloat xPosition;
    GLfloat yPosition;
    GLfloat height;
    GLfloat width;
    glm::vec3 colorTop;
    glm::vec3 colorBot;
    glm::vec3 colorOut;
    float value;
public:
    Gauge();
    Gauge(int);
    ~Gauge();
    void setup(glm::vec3 tcolor = glm::vec3( 0, 255, 0 ), glm::vec3 bcolor = glm::vec3( 255, 0, 0 ), glm::vec3 ocolor = glm::vec3( 255, 255, 255 ),
                    float val = 100, GLfloat xPos = 0, GLfloat yPos = 0, GLfloat h = 15, GLfloat w = 100);
    void setValue(float);
    void draw();
};

#endif