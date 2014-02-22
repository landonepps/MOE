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

#ifndef HUD_H_
#define HUD_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include <string>
#include <vector>
#include "HUDelement.h"

using namespace std;

class HUD{
    private:
        vector<HUDelement*> HUDelements;

    public:
        HUD();
        ~HUD();
        void drawElements();
        void addHUDElement(HUDelement*);
};

#endif
