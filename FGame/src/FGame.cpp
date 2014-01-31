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
FGame::FGame()
{
    running = true;

    screen  = NULL;
    width   = 640;
    height  = 480;
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
        /** Listen for event (mouse, keyboard, etc.). **/
        while(SDL_PollEvent(&event))
        {
            OnEvent(&event);
        }

        /** Draw to screen. **/
        OnLoop();
        OnRender();
    }

    /** Free any used resources and exit. **/
    OnCleanup();
    return 0;
}

/***********************************************************************
 * main:      Starts the game and contains main game loop.
 *
 * param1:    The number of arguments.
 *
 * param2:    A multidimensional array containing each argument.
 *
 * returns:   Zero on success and anything less than zero on failure.
***********************************************************************/
int main(int argc, char* argv[])
{
    /** Create and execute the game. **/
    FGame theGame;
    return theGame.OnExecute();
}
