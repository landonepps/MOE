/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      8-Feb-2014
*
* Healthbar class
*******************************************************************************/

#ifndef HEALTHBAR_H_
#define HEALTHBAR_H_

#include "HUDelement.h"

class Healthbar : public HUDelement{
private:
    int xPosition;
    int yPosition;
    int height;
    int width;
    int color[4];
    int ocolor[4];
    float health;
public:
    Healthbar();
    Healthbar(int);
    ~Healthbar();
    void setup(float hp = 100, int xPos = 0, int yPos = 0, int h = 15, int w = 100);
    void draw(SDL_Renderer*);
};

#endif