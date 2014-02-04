/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Frees any used resources.
*******************************************************************************/

#include "FGame.h"      /** Contains prototype for OnCleanup. **/

/***********************************************************************
 * OnCleanup: Frees any used resources.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnCleanup()
{
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(screen);
    SDL_Quit();
}
