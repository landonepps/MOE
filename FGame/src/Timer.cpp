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

Timer::Timer() : HUDelement(){}

Timer::Timer(int id) : HUDelement(id){}

void Timer::setup(const string &fontFile, SDL_Color cl,int fontSize, 
            int precision, int xPos, int yPos, int sec, int id)
{
    this->precision = precision;
    xPosition = xPos;
    yPosition = yPos;
    seconds = sec;
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL) {
        cerr << "failed to load font";
    }
    color = cl;
}

Timer::~Timer(){
    TTF_CloseFont(font);
}

void Timer::setTime(float timeLeft){
    seconds = timeLeft;
}

void Timer::draw(SDL_Renderer* renderer){

    stringstream message;
    message << fixed << setprecision(precision) << seconds;
    
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.str().c_str(), color);
    if (surf == nullptr){
		TTF_CloseFont(font);
		return;
	}

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surf);
    
    if (texture == NULL) {
        cerr << "error creating texture" << endl;
    }

    SDL_Rect rect;
    rect.x = xPosition;
    rect.y = yPosition;

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surf);

    SDL_DestroyTexture(texture);
}