/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       2/22/2014
*
* Parent class for object elements
*******************************************************************************/

#ifndef OBJECT_H_
#define OBJECT_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <string>
#include <vector>
#include "objectElement.h"

using namespace std;

class Object{
private:
    vector<objectElement*> objectElements;

public:
    Object();
    ~Object();
    void drawElements();
    void addObjectElement(objectElement*);
};

#endif
