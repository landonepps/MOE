/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:      7-Feb-2014
 *
 * Counter class
*******************************************************************************/

#ifndef Counter_H_
#define Counter_H_

#include <string>
#include <sstream>
#ifdef _MSC_VER
#include <SDL_ttf.h>
#else
#ifdef __APPLE__
#include <SDL2_ttf/SDL_ttf.h>
#else
#include <SDL2/SDL_ttf.h>
#endif
#endif

#include "HUDelement.h"
#include "Clock.h"

using namespace std;

class Counter : public HUDelement{
    private:
        int xPosition;
        int yPosition;
        float value;
        int precision;
        TTF_Font* font;
        SDL_Color color;
    public:
        Counter();
        Counter(int);
        ~Counter();
        void setup(const string &fontFile, SDL_Color cl,int xPos = 0, int yPos = 0,
                   int fontSize = 36, int precision = 0,  int id = NULL);
        void draw(SDL_Renderer*);
        void setValue(float timeLeft);
};

#endif
