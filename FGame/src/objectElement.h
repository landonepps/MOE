/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       2/22/2014
*
* Parent class for hud elements
*******************************************************************************/

#ifndef OBJECTELEMENT_H_
#define OBJECTELEMENT_H_

#ifdef _MSC_VER
#include <SDL.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <SDL2/SDL.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#endif

class objectElement{
private:
    // id ideally used for debugging or specific HUD manipulation.
    int id;

public:
    objectElement(){ id = 0; };
    objectElement(int id){ this->id = id; };
    virtual ~objectElement(){};

    // Virtual function to ensure child classes have a way to draw themselves.
    // It also envokes that draw function when called
    virtual void draw() = 0;
};

#endif
