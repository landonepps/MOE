/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       9-Feb-2014
*
* Object implementation file
*******************************************************************************/

#include "Object.h"

Object::Object(){}

Object::~Object(){}

void Object::drawElements(){
    for (unsigned int i = 0; i < objectElements.size(); i++){
        objectElements[i]->draw();
    }
}

void Object::addObjectElement(objectElement* element){
    objectElements.push_back(element);
}