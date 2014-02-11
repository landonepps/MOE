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
    
    //TODO: Remove later
    background.draw(0, 0);
    // poorImg.draw(p1.xLoc+70, p1.yLoc+200, 0, p1.aniControl.getCurrentFrame() * 200,140,200);
    // poorImg2.draw(p2.xLoc+270, p2.yLoc+200, 0, p2.aniControl.getCurrentFrame() * 200,140,200);
    //poorAnim.getCurrentFrame() * 200, 140, 200);
    p1.draw();
    p2.draw();
    foreground.draw(0, 0);
    theHUD.drawElements(renderer);    

    /** Swap buffers. **/
    SDL_RenderPresent(renderer);
}
