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

    /** Initialize the clock for the main game loop. **/
    mainClock.init();

    /** Set opengl attributes, enable double buffering. **/
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 5);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    /** Creates the main window centered and allows opengl. Not sure if
     *  double buffer is already enabled. **/
    if((window = SDL_CreateWindow("FGame",
                                  SDL_WINDOWPOS_CENTERED,
                                  SDL_WINDOWPOS_CENTERED,
                                  width, height,
                                  SDL_WINDOW_OPENGL )) == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create screen: %s\n", SDL_GetError());
        return false;
    }
    
    /** Creates the gl context with our given attributes. **/
    if((context = SDL_GL_CreateContext(window)) == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create context: %s\n", SDL_GetError());
        return false;
    }

    /** Creates main renderer using GPU accelerating and VSYNC **/
    if((renderer = SDL_CreateRenderer(window,
                                      -1,
                                      SDL_RENDERER_ACCELERATED |
                                      SDL_RENDERER_PRESENTVSYNC)) == NULL) {
        fprintf(stderr, "ERORR: Failed to create renderer: %s\n",
                SDL_GetError());
        return false;
    }

    /** Enable TTF loading (fonts) **/
    TTF_Init();

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
    
    // load audio for testing
    #ifdef _WIN32
        bgm.loadMusic(".\\assets\\bgm.wav");
        bgm.play();
    #else
        bgm.loadMusic("./assets/bgm.wav");
        bgm.play();
    #endif

    return true;
}
