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

#ifndef COUNTER_H_
#define COUNTER_H_

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

using namespace std;

class Counter : public HUDelement{
    private:
        double xPosition;
        double yPosition;
        float value;
        int precision;
        TTF_Font* font;
        SDL_Color color;

    public:
        Counter();
        Counter(int);
        ~Counter();
        void setup(const string &fontFile, const GLubyte& R = 0, const GLubyte& G = 0, const GLubyte& B = 0,
            const double& xPos = 0, const double& yPos = 0, int fontSize = 5, int precision = 0, int id = NULL);
        void draw();
        void setValue(float value);
};

#endif
