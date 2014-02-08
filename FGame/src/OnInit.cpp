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
    }
    
    if((renderer = SDL_CreateRenderer(screen,
                                      -1,
                                      SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        fprintf(stderr, "ERORR: Failed to create renderer: %s\n",
                SDL_GetError());
        return false;
    }

    TTF_Init();

    // set swap to monitor refresh rate
    /*if(SDL_GL_SetSwapInterval(1) == -1)
    {
        fprintf(stderr, "ERROR: Failed to set swap interval: %s\n",
                SDL_GetError());
        return false;
    }*/

    /** Initialize the joysticks. **/
    int numJoysticks = SDL_NumJoysticks();
    if(numJoysticks < 0)
    {
        fprintf(stderr, "ERROR: NumJoysticks failed: %s\n", SDL_GetError());
        return false;
    }
    else if(numJoysticks > 0)
    {
        /** Open joystick1. **/
        joystick1 = SDL_JoystickOpen(0);
        if(!joystick1)
        {
            fprintf(stderr, "ERROR: Couldn't open joystick1: %s\n",
                    SDL_GetError());
            return false;
        }
    }
    else
    {
        /** Do nothing. **/
    }
    // load images for testing
    character.loadImage("character.png", renderer);
    scene.loadImage("scene.jpg", renderer);

    SDL_Color color = {255, 255, 255};
    timer.setup("font.ttf", color);
    /** Initialize the clock for the main game loop. **/
    mainClock.init();
    
    return true;
}
