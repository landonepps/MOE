/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      7-Feb-2014
*
* Treasure class
*******************************************************************************/

#include "Treasure.h"

Treasure::Treasure() : objectElement()
{
    x = 0;
    y = 0;
    z = 0;
    theMesh = NULL;
    rotate = false;
    clockwise = false;
    bob = false;
    rotateSpeed = 1;
    rotateAngle = 0;
    bobSpeed = 1;
    bobMax = 20;
    bobMin = 20;
    reached = false;
}

Treasure::Treasure(int id) : objectElement(id)
{
    x = 0;
    y = 0;
    z = 0;
    theMesh = NULL;
    rotate = false;
    clockwise = false;
    bob = false;
    rotateSpeed = 1;
    rotateAngle = 0;
    bobSpeed = 1;
    bobMax = 20;
    bobMin = 20;
    reached = false;
}

/***********************************************************************
* setup:   Sets up the Treasure HUD type using developer specified variables
*
* fontfile: the name of the .ttf file
* cl: font color
* xPos: x coordinate of where to place the Treasure
* yPos: y coordinate of where to place the Treasure
* fontSize: size of the font
* precision: precision of Treasure desired by user.
* id: an id for this HUD type if desired.
*
* returns:   void.
***********************************************************************/
void Treasure::setup(char const* filename)
{
    theMesh = new Mesh(filename);
}

Treasure::~Treasure(){

}
/***********************************************************************
* setTime:   Sets the time remaining to be displayed
*
* timeLeft:  the time remaining in the round
*
* returns:   void.
***********************************************************************/
void Treasure::setLocation(GLfloat x, GLfloat y, GLfloat z){
    this->x = x;
    this->y = y;
    this->z = z;
}

/***********************************************************************
* draw:   Simply draws the Treasure to the screen
*
* renderer: The SDL renderer to be rendered to.
*
* returns:   void.
***********************************************************************/
void Treasure::draw(){
    glPushMatrix();
    if (bob){
        if (y >= bobMax){
            reached = true;
        }
        if (y <= bobMin){
            reached = false;
        }

        if (!reached){
            y += bobSpeed;
        }
        else if (reached){
            y -= bobSpeed;
        }
    }
    glTranslatef(x, y, z);
    glScalef(25, 25, 25);
    if (rotate){
        if (clockwise){
            rotateAngle += rotateSpeed;
        }
        else{
            rotateAngle -= rotateSpeed;
        }
        glRotatef(rotateAngle, 0, 1, 0);
    }
    theMesh->draw();
    glPopMatrix();
}

void Treasure::setRotate(bool rotateSet, bool clockwiseSet, GLfloat speed){
    rotate = rotateSet;
    clockwise = clockwiseSet;
    rotateSpeed = speed;
}

void Treasure::setBob(bool bobSet, GLfloat speed, GLfloat bobMax, GLfloat bobMin){
    bob = bobSet;
    bobSpeed = speed;
    this->bobMax = y + bobMax;
    this->bobMin = y - bobMin;
}

void Treasure::toggleClockwise(){
    clockwise = !clockwise;
}

void Treasure::toggleBob(){
    bob = !bob;
}

