/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      8-Feb-2014
*
* Gauge implementation file
*******************************************************************************/

#include "Gauge.h"
/***********************************************************************
* Gauge: sets the default outline to white and value to green
*
* returns:   void.
***********************************************************************/
Gauge::Gauge() : HUDelement(){
    colorTop.x = 0;
    colorTop.y = 255;
    colorTop.z = 0;

    colorBot.x = 255;
    colorBot.y = 0;
    colorBot.z = 0;

    colorOut.x = 255;
    colorOut.y = 255;
    colorOut.z = 255;

    value = 100;
    xPosition = 0;
    yPosition = 0;
    height = 15;
    width = 100;
}

Gauge::Gauge(int id) : HUDelement(id){
    colorTop.x = 0;
    colorTop.y = 255;
    colorTop.z = 0;

    colorBot.x = 255;
    colorBot.y = 0;
    colorBot.z = 0;

    colorOut.x = 255;
    colorOut.y = 255;
    colorOut.z = 255;

    value = 100;
    xPosition = 0;
    yPosition = 0;
    height = 15;
    width = 100;
}

/***********************************************************************
* setup:   Sets up the Gauge HUD type using developer specified variables
*
* value: current player value
* xPos: x coordinate of where to place the Gauge
* yPos: y coordinate of where to place the Gauge
* h: height of the Gauge dimension
* w: width of the Gauge dimension
*
* returns:   void.
***********************************************************************/
void Gauge::setup(glm::vec3 tcolor, glm::vec3 bcolor, glm::vec3 ocolor, float val, GLfloat xPos, GLfloat yPos, GLfloat h, GLfloat w)
{
    value = val;
    xPosition = xPos;
    yPosition = yPos;
    height = h;
    width = w;
    colorTop = tcolor;
    colorBot = bcolor;
    colorOut = ocolor;
}

Gauge::~Gauge(){

}
/***********************************************************************
* setvalue: Sets the current value
* 
* val: current player value
*
* returns:   void.
***********************************************************************/
void Gauge::setValue(float val){
    value = val;
}

/***********************************************************************
* draw: draws the Gauge to the screen by taking a precentage of the
*           value remaining and scaling the green Gauge down
*
* returns:   void.
***********************************************************************/
void Gauge::draw()
{
    GLfloat currentValue = (width * value) / 100;

    // draws a colorBot background behind the colorTop bar
    glBegin(GL_POLYGON);
    glColor3f(colorBot.x, colorBot.y, colorBot.z);
    glVertex2f(xPosition, yPosition + height);
    glVertex2f(xPosition + width, yPosition + height);
    glVertex2f(xPosition + width, yPosition);
    glVertex2f(xPosition, yPosition);
    glEnd();

    // colorTop bar
    glBegin(GL_POLYGON);
    glColor3f(colorTop.x, colorTop.y, colorTop.z);
    glVertex2f(xPosition, yPosition + height);
    glVertex2f(xPosition + currentValue, yPosition + height);
    glVertex2f(xPosition + currentValue, yPosition);
    glVertex2f(xPosition, yPosition);
    glEnd();

    // outline
    glBegin(GL_LINE_LOOP);
    glColor3f(colorOut.x, colorOut.y, colorOut.z);
    glVertex2f(xPosition, yPosition);
    glVertex2f(xPosition + width, yPosition);
    glVertex2f(xPosition + width, yPosition + height);
    glVertex2f(xPosition, yPosition + height);
    glEnd();
}