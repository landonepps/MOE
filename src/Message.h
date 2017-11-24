/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      7-Feb-2014
*
* Message class
*******************************************************************************/

#ifndef Message_H_
#define Message_H_

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

class Message : public HUDelement{
private:
    double xPosition;
    double yPosition;
    string value;
    int precision;
    TTF_Font* font;
    SDL_Color color;

public:
    Message();
    Message(int);
    ~Message();
    void setup(const string &fontFile, const GLubyte& R = 0, const GLubyte& G = 0, const GLubyte& B = 0,
        const double& xPos = 0, const double& yPos = 0, int fontSize = 5, int precision = 0, int id = NULL);
    void draw();
    void setValue(string value);
};

#endif
