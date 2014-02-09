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
                                  0 )) == NULL)
    {
        fprintf(stderr, "ERROR: Failed to create screen: %s\n", SDL_GetError());
        return false;
    }
    
    /** Creates main renderer using GPU accelerating and VSYNC **/
    if((renderer = SDL_CreateRenderer(screen,
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
    
    SDL_Color timerColor {255, 255, 255};
    
    // load images for testing
#ifdef _WIN32
    character.loadImage(".\\assets\\character1.png", renderer);
    background.loadImage(".\\assets\\stage1bg.png", renderer);
    foreground.loadImage(".\\assets\\stage1fg.png", renderer);
    
    poorImg.loadImage(".\\assets\\poor.png", renderer);
    
    timer.setup(".\\assets\\font.ttf", timerColor);
#else
    character.loadImage("./assets/character1.png", renderer);
    background.loadImage("./assets/stage1bg.png", renderer);
    foreground.loadImage("./assets/stage1fg.png", renderer);
    
    poorImg.loadImage("./assets/poor.png", renderer);
    
    timer.setup("./assets/font.ttf", timerColor);
    
    bgm.loadMusic("./assets/bgm.wav");
    bgm.playMusic();
    
#endif
    
    /** Set frame rate to every 150 milliseconds. **/
    poorAnim.setFrameRate(150);

    hp.setup(30,70,5,30,200);
    /** Initialize the clock for the main game loop. **/
    mainClock.init();
    
    return true;
}
