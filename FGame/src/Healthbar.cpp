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
/***********************************************************************
* Healthbar: sets the default outline to white and health to green
*
* returns:   void.
***********************************************************************/
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

/***********************************************************************
* setup:   Sets up the Healthbar HUD type using developer specified variables
*
* hp: current player health
* xPos: x coordinate of where to place the healthbar
* yPos: y coordinate of where to place the healthbar
* h: height of the healthbar dimension
* w: width of the healthbar dimension
*
* returns:   void.
***********************************************************************/
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
/***********************************************************************
* setHealth: Sets the current health
* 
* hp: current player health
*
* returns:   void.
***********************************************************************/
void Healthbar::setHealth(float hp){
    health = hp;
}

/***********************************************************************
* draw: draws the healthbar to the screen by taking a precentage of the
*           health remaining and scaling the green healthbar down
*
* renderer: SDL_renderer pointer
*
* returns:   void.
***********************************************************************/
void Healthbar::draw(SDL_Renderer* renderer)
{
    int currentHealth = (width * health) / 100;

    // draws a red background behind the green bar
    SDL_Rect maxRect = { xPosition, yPosition, width, height };
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 0);
    SDL_RenderFillRect(renderer, &maxRect);

    // green bar
    SDL_Rect fillRect = { xPosition, yPosition, currentHealth, height };
    SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
    SDL_RenderFillRect(renderer, &fillRect);

    // outline
    SDL_Rect outlineRect = { xPosition, yPosition, width, height };
    SDL_SetRenderDrawColor(renderer, ocolor[0], ocolor[1], ocolor[2], ocolor[3]);
    SDL_RenderDrawRect(renderer, &outlineRect);
}