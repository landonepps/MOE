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
#include <cstdlib>
#include "FGame.h"      /** Contains OnInit prototype. **/
#include <time.h>

/***********************************************************************
 * OnInit:    Initializes Counter, audio, video, cdrom, and joystick.
 *            Also, creates the main window centered and allows opengl.
 *
 * returns:   True on success and false on failure.
***********************************************************************/
bool FGame::OnInit()
{
    srand(time(0));
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

    currentLevel = 1;

    /** Initialize the clock for the main game loop. **/
    mainClock->init();

    /** Add a player stat for furniture count**/
    player.addStat(1, 0);

    enemy.addStat(1, 0); 

    /** Load music, room, pickups and decorations,**/
#ifdef _WIN32
    bgm.loadMusic(".\\assets\\adventure.wav");
    pickUp.loadSFX(".\\assets\\yes.wav");
    bgm.play();

    sky->loadSky(".\\assets\\skybox.ply", ".\\assets\\skybox_texture.jpg");
    
    terrain->load(".\\assets\\terrain2.bmp");
    int horScale = 100;
    terrain->setHorScale(horScale);
    terrain->setPos(glm::vec3(0, 0, 0));
    // terrain.setPos(glm::vec3(terrain.getWidth() * horScale / -2.0, 0, terrain.getLength() * horScale / -2.0));
    int vertScale = 1000;
    terrain->setVertScale(vertScale);
    int playerStartX = terrain->getWidth() * horScale / -2.0;
    int playerStartZ = terrain->getLength() * horScale / -2.0;
    player.setPos(glm::vec3(playerStartX, -terrain->getHeight(-playerStartX, -playerStartZ) - PLAYER_HEIGHT, playerStartZ));
    sky->setPos(player.getPos());

    // Create the light.
    GLfloat ambient[]   = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse[]   = {0.8, 0.8, 0.8, 1.0};
    GLfloat specular[]  = {0.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat position[]  = {(float)playerStartX, (float)vertScale, (float)playerStartZ, 1.0};
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);

    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);

    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glm::vec3 randomRange;
    float envx = (Skybox::getInstance()->getDimensions().x / 2) - 50;
    float envy = Skybox::getInstance()->getDimensions().y - 50;
    float envz = (Skybox::getInstance()->getDimensions().z / 2) - 50;

    randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
    randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
    randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
    enemy.setup(".\\assets\\puff.ply", ".\\assets\\poorpuff.png");
    enemy.setScale(25, 25, 25);
    enemy.setLocation(randomRange.x, randomRange.y, randomRange.z);

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup(".\\assets\\poltroncina.ply", ".\\assets\\poltroncina.png");
        temp.setScale(25,25,25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setBob(true, 5, 6, 6);
        temp.setRotate(true,false,25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup(".\\assets\\tavolo1.ply", ".\\assets\\tavolo1.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setRotate(true, true, 25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup(".\\assets\\letto.ply", ".\\assets\\letto.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setBob(true, 10, 5, 5);
        treasures.push_back(temp);
    }

    fpsCount.setup(".\\assets\\font.ttf", 255, 0, 0, 50, 50, 25);

    furnitureCount.setup(".\\assets\\font.ttf", 0, 255, 0, WIN_WIDTH / 2, 50, 25);

    enemyFurnitureCount.setup(".\\assets\\font.ttf", 0, 0, 255, WIN_WIDTH - 50, 50, 25);

    win.setup(".\\assets\\font.ttf", 0, 255, 0, WIN_WIDTH / 2, WIN_HEIGHT / 2, 25);
#else
    bgm.loadMusic("./assets/adventure.wav");
    pickUp.loadSFX("./assets/yes.wav");
    bgm.play();

    sky->loadSky("./assets/skybox.ply", "./assets/skybox_texture.jpg");
    
    terrain->load("./assets/terrain2.bmp");
    int horScale = 100;
    terrain->setHorScale(horScale);
    terrain->setPos(glm::vec3(0, 0, 0));
    // terrain.setPos(glm::vec3(terrain.getWidth() * horScale / -2.0, 0, terrain.getLength() * horScale / -2.0));
    int vertScale = 1000;
    terrain->setVertScale(vertScale);
    int playerStartX = terrain->getWidth() * horScale / -2.0;
    int playerStartZ = terrain->getLength() * horScale / -2.0;
    player.setPos(glm::vec3(playerStartX, -terrain->getHeight(-playerStartX, -playerStartZ) - PLAYER_HEIGHT, playerStartZ));
    sky->setPos(player.getPos());
    
    // Create the light.
    GLfloat ambient[]   = {0.2, 0.2, 0.2, 1.0};
    GLfloat diffuse[]   = {0.8, 0.8, 0.8, 1.0};
    GLfloat specular[]  = {0.0, 0.0, 0.0, 1.0};
    GLfloat shininess[] = {50.0};
    GLfloat position[]  = {(float)playerStartX, (float)vertScale, (float)playerStartZ, 1.0};
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    
    glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, shininess);
    
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_SHININESS, shininess);
    glLightfv(GL_LIGHT0, GL_POSITION, position);

    glm::vec3 randomRange;
    float envx = (Skybox::getInstance()->getDimensions().x / 2) - 50;
    float envy = Skybox::getInstance()->getDimensions().y - 50;
    float envz = (Skybox::getInstance()->getDimensions().z / 2) - 50;

    randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
    randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
    randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
    enemy.setup("./assets/puff.ply", "./assets/poorpuff.png");
    enemy.setScale(25, 25, 25);
    enemy.setLocation(randomRange.x, randomRange.y, randomRange.z);

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup("./assets/poltroncina.ply", "./assets/poltroncina.png");
        temp.setScale(25,25,25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setBob(true, 5, 6, 6);
        temp.setRotate(true,false,25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup("./assets/tavolo1.ply", "./assets/tavolo1.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setRotate(true, true, 25);
        treasures.push_back(temp);
    }

    for (int i = 0; i < 5; i++){
        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
        Treasure temp;
        temp.setup("./assets/letto.ply", "./assets/letto.png");
        temp.setScale(25, 25, 25);
        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
        temp.setBob(true, 10, 5, 5);
        treasures.push_back(temp);
    }

    fpsCount.setup("./assets/font.ttf", 255, 0, 0, 50, 50, 25);

    furnitureCount.setup("./assets/font.ttf", 0, 255, 0, WIN_WIDTH / 2, 50, 25);
    
    enemyFurnitureCount.setup("./assets/font.ttf", 0, 0, 255, WIN_WIDTH - 50, 50, 25);

    win.setup("./assets/font.ttf", 0, 255, 0, WIN_WIDTH / 2, WIN_HEIGHT / 2, 25);
#endif

    /**Add all the furniture to the collections**/
    for(unsigned int i = 0; i < treasures.size();i++){
        collectables.addPropElement(&treasures[i]);
    }

    totalTreasures = treasures.size();

    /**Setup timer bar add all HUD elements to HUD**/
    timer.setup(90);

    theHUD.addHUDElement(&timer);

    theHUD.addHUDElement(&fpsCount);

    theHUD.addHUDElement(&furnitureCount);

    theHUD.addHUDElement(&enemyFurnitureCount);

    theHUD.addHUDElement(&win);

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

    // What to do when we run out of texture at the edge.
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP );

    // How to map the discrete texels to the frame buffer.
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
    glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );

    return true;
}
