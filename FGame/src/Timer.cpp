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

#include "Timer.h"
#include <iostream>
#include <iomanip>

Timer::Timer() : HUDelement()
{
    xPosition = 0;
    yPosition = 0;
    seconds   = 0.0f;
    precision = 0;
    font      = NULL;
}

Timer::Timer(int id) : HUDelement(id)
{
    xPosition = 0;
    yPosition = 0;
    seconds   = 0.0f;
    precision = 0;
    font      = NULL;
}

/***********************************************************************
* setup:   Sets up the timer HUD type using developer specified variables
*
* fontfile: the name of the .ttf file
* cl: font color 
* xPos: x coordinate of where to place the timer
* yPos: y coordinate of where to place the timer
* fontSize: size of the font
* precision: precision of timer desired by user.
* id: an id for this HUD type if desired.
*
* returns:   void.
***********************************************************************/
void Timer::setup(const string &fontFile, SDL_Color cl, int xPos, int yPos,
                  int fontSize, int precision,  int id)
{
    this->precision = precision;
    xPosition = xPos;
    yPosition = yPos;
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL) {
		string error = TTF_GetError();
        cerr << "failed to load font: " << fontFile << " " << TTF_GetError() << endl;
    }
    color = cl;
}

Timer::~Timer(){
    TTF_CloseFont(font);
}
/***********************************************************************
* setTime:   Sets the time remaining to be displayed
*
* timeLeft:  the time remaining in the round
*
* returns:   void.
***********************************************************************/
void Timer::setTime(float timeLeft){
    seconds = timeLeft;
}

/***********************************************************************
 * draw:   Simply draws the Timer to the screen
 *
 * renderer: The SDL renderer to be rendered to.
 *
 * returns:   void.
***********************************************************************/
void Timer::draw(SDL_Renderer* renderer){

    stringstream message;
    message << fixed << setprecision(precision) << seconds;
    
    // Create the surface to copy to the renderer
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.str().c_str(), color);
    if (surf == NULL){
		TTF_CloseFont(font);
		return;
	}

    // Create the texture from the surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    
    if (texture == NULL) {
        cerr << "error creating texture" << endl;
    }

    SDL_Rect rect;
    rect.x = xPosition;
    rect.y = yPosition;

    // Set texture dimensions and copy to the renderer
    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    // Cleans up the surface and texture
    SDL_FreeSurface(surf);

    SDL_DestroyTexture(texture);
}
