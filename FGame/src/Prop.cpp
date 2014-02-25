/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       9-Feb-2014
*
* Prop implementation file
*******************************************************************************/

#include "Prop.h"

Prop::Prop(){}

Prop::~Prop(){}

void Prop::drawElements(){
    for (unsigned int i = 0; i < PropElements.size(); i++){
        PropElements[i]->draw();
    }
}

void Prop::addPropElement(PropElement* element){
    PropElements.push_back(element);
}

void Prop::removePropElement(){
    PropElements.pop_back();
}

PropElement* Prop::getPropElement(int i){
    return PropElements[i];
}