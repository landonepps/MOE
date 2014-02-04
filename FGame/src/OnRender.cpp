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
    
    glClear(GL_COLOR_BUFFER_BIT);
    
    /** Swap buffers. **/
    SDL_GL_SwapWindow(screen);
}
