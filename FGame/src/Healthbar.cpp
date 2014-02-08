/*******************************************************************************
* Authors:    Jesse Clary
*             Landon Epps
*             Andrew Kliphon
*             Jeremy Stark
* Assignment: MOE (Most Optimistic Engine)
* Class:      4342, Spring 2014
* Date:      8-Feb-2014
*
* Healthbar implementation file
*******************************************************************************/

#include "Healthbar.h"

Healthbar::Healthbar() : HUDelement(){
    color[0] = 0;
    color[1] = 255;
    color[2] = 0;
    color[3] = 255;

    ocolor[0] = 255;
    ocolor[1] = 255;
    ocolor[2] = 255;
    ocolor[3] = 255;
}

Healthbar::Healthbar(int id) : HUDelement(id){}

void Healthbar::setup(float hp, int xPos, int yPos, int h, int w)
{
    health = hp;
    xPosition = xPos;
    yPosition = yPos;
    height = h;
    width = w;
}

Healthbar::~Healthbar(){

}

void Healthbar::draw(SDL_Renderer* renderer)
{
    int currentHealth = (width * health) / 100;

    SDL_Rect fillRect = { xPosition, yPosition, width, height };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(renderer, &fillRect);

    fillRect = { xPosition, yPosition, currentHealth, height };
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(renderer, &fillRect);

    SDL_Rect outlineRect = { xPosition, yPosition, width, height };
    SDL_SetRenderDrawColor(renderer, ocolor[0], ocolor[1], ocolor[2], ocolor[3]);
    SDL_RenderDrawRect(renderer, &outlineRect);
}