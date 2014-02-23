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

Treasure::Treasure() : PropElement()
{
    position = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
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

Treasure::Treasure(int id) : PropElement(id)
{
    position = glm::vec3(0, 0, 0);
    scale = glm::vec3(1, 1, 1);
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
* setup:   Sets up the Treasure prop type using developer specified meshes
*
* filename: name of the mesh file
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
* setTime:   Sets the location of the object
*
* x: x position
* y: y position
* z: z position
*
* returns:   void.
***********************************************************************/
void Treasure::setLocation(GLfloat x, GLfloat y, GLfloat z){
    position = glm::vec3(x, y, z);
}

/***********************************************************************
* setScale:   Sets the scale of the object
*
* x: x scale
* y: y scale
* z: z scale
*
* returns:   void.
***********************************************************************/
void Treasure::setScale(GLfloat x, GLfloat y, GLfloat z){
    scale = glm::vec3(x, y, z);
}

/***********************************************************************
* draw:   Simply draws the Treasure to the screen with specified flags
*           to enable bobbing or rotating.
*
* returns:   void.
***********************************************************************/
void Treasure::draw(){
    glPushMatrix();
    if (bob){
        if (position.y >= bobMax){
            reached = true;
        }
        if (position.y <= bobMin){
            reached = false;
        }

        if (!reached){
            position.y += bobSpeed;
        }
        else if (reached){
            position.y -= bobSpeed;
        }
    }
    glTranslatef(position.x, position.y, position.z);
    glScalef(scale.x, scale.y, scale.z);
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

/***********************************************************************
* setRotate: Sets the rotate flag, cockwise flag, and the speed of the rotation
*
* rotateSet: true for rotation, false for no rotation
* clockwiseSet: true to rotate clockwise, false to rotate counterclockwise
* speed: speed of rotate by how many degrees are added each frame
*
* returns:   void.
***********************************************************************/
void Treasure::setRotate(bool rotateSet, bool clockwiseSet, GLfloat speed){
    rotate = rotateSet;
    clockwise = clockwiseSet;
    rotateSpeed = speed;
}

/***********************************************************************
* setBob: Sets the bob flag, speed, bobMax, bobMin
*
* bobSet: true for bobbing, false for no bobbing
* speed: set the speed of how many pixels the object will bob each frame
* bobMax: The maximum height of the bob
* bobMin: The minimum height of the bob
*
* returns:   void.
***********************************************************************/
void Treasure::setBob(bool bobSet, GLfloat speed, GLfloat bobMax, GLfloat bobMin){
    bob = bobSet;
    bobSpeed = speed;
    this->bobMax = position.y + bobMax;
    this->bobMin = position.y - bobMin;
}

/***********************************************************************
* toggleClockwise: flips the clockwise flag
*
* returns:   void.
***********************************************************************/
void Treasure::toggleClockwise(){
    clockwise = !clockwise;
}

/***********************************************************************
* toggleBob: flips the bob flag
*
* returns:   void.
***********************************************************************/
void Treasure::toggleBob(){
    bob = !bob;
}

/***********************************************************************
* getPosition: returns a vec3 of the position of the object
*
* returns:   vec3
***********************************************************************/
glm::vec3 Treasure::getPosition(){
    return position;
}


