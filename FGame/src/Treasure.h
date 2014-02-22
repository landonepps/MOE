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

#include "objectElement.h"
#include "Mesh.h"

class Treasure : public objectElement{
private:
    Mesh *theMesh;
    float x, y, z;
    bool rotate, clockwise, bob;
    int rotateSpeed, rotateAngle, bobSpeed, bobMax, bobMin;
public:
    Treasure();
    Treasure(int);
    ~Treasure();
    void setup(char const* filename);
    void setLocation(float x, float y, float z);
    void setRotate(bool, bool, int speed = 1);
    void setBob(bool, int speed = 1, int bobMax = 20, int bobMin = 20);
    void toggleBob();
    void toggleClockwise();
    void draw();
};

#endif
