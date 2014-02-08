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

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class HUDelement{
    private:
        int id;

    public:
        HUDelement(int id){this->id = id;};
        // virtual ~HUDelement() = 0;
        virtual void draw(SDL_Renderer*) = 0;
};

#endif