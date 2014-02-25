/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Initializes Counter, audio, video, cdrom, and joystick. Also, creates the main
 * window centered and allows opengl.
 *
 * Free models were obtained from:
 * http://www.blender-models.com/model-downloads/furniture/id/low-poly-furniture/
 * Music:
 * http://www.newgrounds.com/audio/listen/407285
 *******************************************************************************/

#include <stdio.h>     /** Needed to print errors. **/
#include "FGame.h"      /** Contains OnInit prototype. **/

/***********************************************************************
 * OnInit:    Initializes Counter, audio, video, cdrom, and joystick.
 *            Also, creates the main window centered and allows opengl.
 *
 * returns:   True on success and false on failure.
***********************************************************************/
bool FGame::OnInit()
{
    /** Initializes Counter, audio, video, cdrom, and joystick. **/
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        fprintf(stderr, "ERROR: SDL_Init failed: %s\n", SDL_GetError());
        return false;
    }

    /** Set opengl attributes, enable double buffering. **/
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
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

    /** Initialize text **/
    TTF_Init();
    
    /** Initilize image **/
    IMG_Init(IMG_INIT_PNG);

    /** Initialize the clock for the main game loop. **/
    mainClock->init();

    /** Add a player stat for furniture count**/
    player.addStat(1, 0);

    /** Load music, room, pickups and decorations,**/
#ifdef _WIN32
    bgm.loadMusic(".\\assets\\adventure.wav");
    pickUp.loadSFX(".\\assets\\yes.wav");
    bgm.play();
    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup(".\\assets\\poltroncina.ply", ".\\assets\\poltroncina.png");
        temp.setScale(25,25,25);
        temp.setLocation(0, temp.getDimensions().y, 50);
        temp.setBob(true, 5, 6, 6);
        temp.setRotate(true,false,25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup(".\\assets\\tavolo1.ply", ".\\assets\\tavolo1.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(0, temp.getDimensions().y, -50);
        temp.setRotate(true, true, 25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup(".\\assets\\letto.ply", ".\\assets\\letto.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(0, temp.getDimensions().y, 0);
        temp.setBob(true, 10, 5, 5);
        treasures.push_back(temp);
    }

    Treasure temp;
    temp.setup(".\\assets\\comodino.ply", ".\\assets\\comodino.png");
    temp.setScale(300, 300, 300);
    temp.setLocation(-430, temp.getDimensions().y + 35, -450);
    notTreasures.push_back(temp);

    temp.setup(".\\assets\\puff.ply", ".\\assets\\puff.png");
    temp.setScale(300, 300, 300);
    temp.setLocation(0, temp.getDimensions().y - 160, 420);
    notTreasures.push_back(temp);

    fpsCount.setup(".\\assets\\font.ttf",255,0,0,50,50,25);

    furnitureCount.setup(".\\assets\\font.ttf",0,255,0,WIN_WIDTH/2,50,25);
    env.loadEnv(".\\assets\\room.ply", ".\\assets\\roomtex.jpg");
#else
    bgm.loadMusic("./assets/adventure.wav");
    pickUp.loadSFX("./assets/yes.wav");
    bgm.play();
    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup("./assets/puff.ply", "./assets/puff.png");
        temp.setBob(true, 0.5, 15, 15);
        temp.setRotate(true, true, 25);
        temp.setScale(25, 25, 25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup("./assets/tavolo1.ply", "./assets/tavolo1.png");
        temp.setRotate(true, true, 25);
        temp.setScale(25, 25, 25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        Treasure temp;
        temp.setup("./assets/letto.ply", "./assets/letto.png");
        temp.setBob(true, 0.5, 15, 15);
        temp.setScale(25, 25, 25);
        treasures.push_back(temp);
    }

    Treasure temp;
    temp.setup("./assets/comodino.ply", "./assets/comodino.png");
    temp.setScale(300, 300, 300);
    temp.setLocation(-430, temp.getDimensions().y + 35, -450);
    notTreasures.push_back(temp);

    temp.setup("./assets/puff.ply", "./assets/puff.png");
    temp.setScale(300, 300, 300);
    temp.setLocation(0, temp.getDimensions().y - 175, 450);
    notTreasures.push_back(temp);

    fpsCount.setup("./assets/font.ttf",255,0,0,50,50,25);
    furnitureCount.setup("./assets/font.ttf", 0, 255, 0, WIN_WIDTH / 2, 50, 25);
    env.loadEnv("./assets/room.ply", "./assets/roomtex.jpg");
#endif

    /**Add all the furniture to the collections**/
    for(int i = 0; i < treasures.size();i++){
        collectables.addPropElement(&treasures[i]);
    }

    for (int i = 0; i < notTreasures.size(); i++){
        decorations.addPropElement(&notTreasures[i]);
    }

    /**Setup timer bar add all HUD elements to HUD**/
    timer.setup(120);

    theHUD.addHUDElement(&timer);

    theHUD.addHUDElement(&fpsCount);

    theHUD.addHUDElement(&furnitureCount);

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

    glEnable( GL_DEPTH_TEST );
    glEnable( GL_CULL_FACE );
    glCullFace( GL_BACK );

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    return true;
}
