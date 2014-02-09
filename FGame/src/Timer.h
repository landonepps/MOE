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
#ifdef _MSC_VER
#include <SDL_ttf.h>
#else
#include <SDL2_ttf/SDL_ttf.h>
#endif

#include "HUDelement.h"
#include "Clock.h"
#include <iostream>

using namespace std;

class Timer : public HUDelement{
    private:
        int xPosition;
        int yPosition;
        float seconds;
        int precision;
        TTF_Font* font;
        SDL_Color color;
    public:
        Timer();
        Timer(int);
        ~Timer();
        void setup(const string &fontFile, SDL_Color cl, int fontSize = 36, 
            int precision = 0, int xPos = 0, int yPos = 0, int id = NULL);
        void draw(SDL_Renderer*);
        void setTime(float timeLeft);
};

#endif