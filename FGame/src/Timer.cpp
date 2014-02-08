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

Timer::~Timer(){
    SDL_DestroyTexture(texture);
}

void Timer::draw(SDL_Renderer* renderer){
    int currentTime = seconds - clock.cyclesToSeconds(clock.getTimeCycles());
    stringstream message;
    message << "I loke p[ee"; // << currentTime;

    SDL_Surface *surf = TTF_RenderText_Blended(font, message.str().c_str(), color);
    if (surf == nullptr){
		TTF_CloseFont(font);
		return;
	}

    texture = SDL_CreateTextureFromSurface(renderer, surf);
    
    if (texture == NULL) {
        cerr << "error creating texture" << endl;
    }

    SDL_Rect rect;
    rect.x = xPosition;
    rect.y = yPosition;

    SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
}