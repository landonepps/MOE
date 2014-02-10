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

#include "FGame.h"      /** Contains event prototypes.  **/

/***********************************************************************
 * OnEvent:   Handles any events caused by user.
 *
 * event:     The event caused by user (ex. button press, mouse etc.).
 *
 * returns:   void.
***********************************************************************/
void FGame::OnEvent(SDL_Event* event)
{
    Events::OnEvent(event);
}

/***********************************************************************
 * OnExit:    Sets the application's running status to false.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnExit()
{
    running = false;
}

/***********************************************************************
 * OnJoyButtonDown: Close application if a joystick button is pressed
 *                  (test).
 *
 * which:     The index of the joystick that reported the event.
 *
 * button:    The index of the button that changed.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnJoyButtonDown(Uint8 which, Uint8 button)
{
    mainClock.setTimeScale(mainClock.getTimeScale() + 0.25);
}
