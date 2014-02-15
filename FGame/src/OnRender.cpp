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
#include <iostream>

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
    
    /** Swap buffers. **/
    SDL_RenderPresent(renderer);
}
