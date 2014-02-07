/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/04/2014
 *
 * Parent class for hud elements
*******************************************************************************/

#ifndef HUDELEMENTS_H_
#define HUDELEMENTS_H_

#include <SDL2\SDL.h>

using namespace std;

class HUDelement{
    private:
        int id;

    public:
        HUDelement(int);
        virtual ~HUDelement();
        virtual void draw();
};

#endif