/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:      7-Feb-2014
 *
 * Timer class
*******************************************************************************/

#ifndef TIMER_H_
#define TIMER_H_

#include <string>
#include <sstream>
#include "SDL_ttf.h"
#include "HUDelement.h"
#include "Clock.h"

using namespace std;

class Timer : public HUDelement{
    private:
        int xPosition;
        int yPosition;
        int seconds;
        SDL_Texture* texture;
        TTF_Font *font;
        SDL_Color color;
        Clock clock;
    public:
        Timer(SDL_Color cl, const string &fontName = NULL,int fontSize = 12, int xPos = 0, int yPos = 0, int sec = 0, 
            int id = NULL) : HUDelement(id)
        {
            xPosition = xPos;
            yPosition = yPos;
            seconds = sec;
            color = cl;
            font = TTF_OpenFont(fontName.c_str(), fontSize);
        }
        ~Timer();
        void draw(SDL_Renderer*);
};

#endif