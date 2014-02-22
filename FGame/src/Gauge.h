/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      8-Feb-2014
*
* Gauge HUD class
*******************************************************************************/

#ifndef GAUGE_H_
#define GAUGE_H_

#include "HUDelement.h"

class Gauge : public HUDelement{
private:
    int xPosition;
    int yPosition;
    int height;
    int width;
    int color[4];
    int ocolor[4];
    float value;
public:
    Gauge();
    Gauge(int);
    ~Gauge();
    void setup(float val = 100, int xPos = 0, int yPos = 0, int h = 15, int w = 100);
    void setValue(float);
    void draw();
};

#endif