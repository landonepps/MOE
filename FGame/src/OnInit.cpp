/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Initializes timer, audio, video, cdrom, and joystick. Also, creates the main
 * window centered and allows opengl.
*******************************************************************************/

#include <stdio.h>     /** Needed to print errors. **/
#include "FGame.h"      /** Contains OnInit prototype. **/

using namespace std;

/***********************************************************************
 * OnInit:    Initializes timer, audio, video, cdrom, and joystick.
 *            Also, creates the main window centered and allows opengl.
 *
 * returns:   True on success and false on failure.
***********************************************************************/
bool FGame::OnInit()
{
    /** Initializes timer, audio, video, cdrom, and joystick. **/
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "ERROR: SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    /** Creates the main window centered and allows opengl. Not sure if
     *  double buffer is already enabled. **/
    if((screen = SDL_CreateWindow("FGame",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  SDL_WINDOW_OPENGL |
                                  SDL_WINDOW_RESIZABLE)) == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create screen: %s\n", SDL_GetError());
        return false;
    } else {
        glContext = SDL_GL_CreateContext(screen);
        // set swap to monitor refresh rate
        SDL_GL_SetSwapInterval(1);
        glClearColor(1, 1, 1, 1);
    }

    return true;
}
