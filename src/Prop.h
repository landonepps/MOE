/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       2/22/2014
*
* Parent class for Prop elements
*******************************************************************************/

#ifndef PROP_H_
#define PROP_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <string>
#include <vector>
#include "PropElement.h"

using namespace std;

class Prop{
private:
    vector<PropElement*> PropElements;

public:
    Prop();
    ~Prop();
    void drawElements();
    void addPropElement(PropElement*);
    void removePropElement();
    PropElement* getPropElement(int i);
    void clear(){
        PropElements.clear();
    }
};

#endif
