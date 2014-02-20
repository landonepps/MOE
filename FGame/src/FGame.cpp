/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Starts the game and contains main game loop.
*******************************************************************************/

#include "FGame.h"  /** Contains prototypes for FGame.cpp. **/

/***********************************************************************
 * FGame:     Sets the game as running and defines the window size.
***********************************************************************/
FGame::FGame() {
    running   = true;

    window    = NULL;
    renderer  = NULL;
    context   = NULL;

    width     = WIN_WIDTH;
    height    = WIN_HEIGHT;

    joystick1 = NULL;

    testMesh = NULL;
    path = "";
}

/***********************************************************************
 * OnExecute: Starts the game and contains main game loop.
 *
 * returns:   Zero on success and anything less than zero on failure.
***********************************************************************/
int FGame::OnExecute()
{
    /** Initialize the game and create window. **/
    if(OnInit() == false)
    {
        /** Errors are printed within OnInit.cpp. **/
        return -1;
    }

    /** Will store mouse, keyboard, etc. events received from user. **/
    SDL_Event event;

    /** Main game loop. Only exit when running is set to false (close
     *  window). **/
    while(running)
    {
        /** Get start time of loop. **/
        Uint64 tBegin = SDL_GetTicks();

        /** Listen for event (mouse, keyboard, etc.). **/
        while(SDL_PollEvent(&event))
        {
            OnEvent(&event);
        }

        /** Draw to screen. **/
        OnLoop();
        OnRender();

        /** Get end time of loop. **/
        Uint64 tEnd = SDL_GetTicks();

        /** Update our clock with the real frame time (in seconds). **/
        mainClock.update((tEnd - tBegin) / 1000.0f);

        /** Might want to call mainClock.singleStep() here, not sure. It is only
         * supposed to update when game is paused. **/
    }

    /** Free any used resources and exit. **/
    OnCleanup();
    return 0;
}

/***********************************************************************
 * main:      Starts the game and contains main game loop.
 *
 * argc:      The number of arguments.
 *
 * argv:      A multidimensional array containing each argument.
 *
 * returns:   Zero on success and anything less than zero on failure.
***********************************************************************/
int main(int argc, char* argv[])
{
    /** Create and execute the game. **/
    FGame theGame;

    /** Get the current path. **/
    theGame.path = string(argv[0]);
    theGame.path = theGame.path.substr(0, theGame.path.rfind('\\'));

    return theGame.OnExecute();
}
