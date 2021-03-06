/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:       9-Feb-2014
*
* HUD implementation file
*******************************************************************************/

#include "HUD.h"


HUD::HUD(){}

HUD::~HUD(){}

void HUD::drawElements(){
    for (unsigned int i = 0; i < HUDelements.size(); i++){
        HUDelements[i]->draw();
    }
}

void HUD::addHUDElement(HUDelement* element){
    HUDelements.push_back(element);
}


