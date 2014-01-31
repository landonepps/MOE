/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Handles any events caused by user (only Quit at the moment).
*******************************************************************************/

#include "FGame.h"      /** Contains prototype for OnEvent.  **/

/***********************************************************************
 * OnEvent:   Handles any events caused by user (only Quit at the
 *            moment).
 *
 * param1:    The event caused by user (ex. button press, mouse etc.).
 *
 * returns:   void.
***********************************************************************/
void FGame::OnEvent(SDL_Event* event)
{
    /** If user clicks the exit button on the window, then set running
     *  to false. **/
    if(event->type == SDL_QUIT)
    {
        running = false;
    }


    /** Handle mouse, keyboard, gamepad etc. **/
}
