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
    color[0] = 0;
    color[1] = 255;
    color[2] = 0;
    color[3] = 255;

    ocolor[0] = 255;
    ocolor[1] = 255;
    ocolor[2] = 255;
    ocolor[3] = 255;
}

Gauge::Gauge(int id) : HUDelement(id){}

/***********************************************************************
* setup:   Sets up the Gauge HUD type using developer specified variables
*
* hp: current player value
* xPos: x coordinate of where to place the Gauge
* yPos: y coordinate of where to place the Gauge
* h: height of the Gauge dimension
* w: width of the Gauge dimension
*
* returns:   void.
***********************************************************************/
void Gauge::setup(float val, int xPos, int yPos, int h, int w)
{
    value = val;
    xPosition = xPos;
    yPosition = yPos;
    height = h;
    width = w;
}

Gauge::~Gauge(){

}
/***********************************************************************
* setvalue: Sets the current value
* 
* hp: current player value
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
* renderer: SDL_renderer pointer
*
* returns:   void.
***********************************************************************/
void Gauge::draw()
{
    int currentValue = (width * value) / 100;

    // draws a red background behind the green bar
    glBegin(GL_POLYGON);
    glColor3f(255, 0, 0);
    glVertex2f(xPosition, yPosition + height);
    glVertex2f(xPosition + width, yPosition + height);
    glVertex2f(xPosition + width, yPosition);
    glVertex2f(xPosition, yPosition);
    glEnd();

    // green bar
    glBegin(GL_POLYGON);
    glColor3f(0, 255, 0);
    glVertex2f(xPosition, yPosition + height);
    glVertex2f(xPosition + currentValue, yPosition + height);
    glVertex2f(xPosition + currentValue, yPosition);
    glVertex2f(xPosition, yPosition);
    glEnd();

    // outline
    glBegin(GL_LINE_LOOP);
    glColor3f(255, 255, 255);
    glVertex2f(xPosition, yPosition);
    glVertex2f(xPosition + width, yPosition);
    glVertex2f(xPosition + width, yPosition + height);
    glVertex2f(xPosition, yPosition + height);
    glEnd();
}