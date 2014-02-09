/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Draws images to the screen.
*******************************************************************************/

#include "FGame.h"      /** Contains OnRender prototype. **/

/***********************************************************************
 * OnRender:  Draws images to the screen.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnRender()
{
    /** Draw image etc. **/
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);

    //TODO: Remove later
    background.draw(0, 0);
    character.draw(70, 170);
    foreground.draw(0, 0);
    hp.draw(renderer);
    timer.draw(renderer);
    
    poorImg.draw(250, 250, 0, poorAnim.getCurrentFrame() * 200, 140, 200);

    /** Swap buffers. **/
    SDL_RenderPresent(renderer);
}
