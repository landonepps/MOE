/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 *
 *
 ******************************************************************************/

#ifndef __MOE__Player__
#define __MOE__Player__

#include "Image.h"
#include "Animation.h"
#include "SFX.h"

class Player {
    int x, y, h, w;
    double xVel, yVel;
    Image img;
    Animation ani;
    SDL_Renderer *renderer;
    SFX punchSound;
    
    /* will remove later */
    bool walking;
    
public:
    Player();
    ~Player();
    void loadPlayer(const char *image, const char *attack, SDL_Renderer *renderer, int x, int y);
    void update(Clock *clock);
    void punch(Clock *clock);
    void walk(Clock *clock);
    void moveLeft();
    void moveRight();
    void halt();
    void draw();
    bool checkCollision(const Player *other);
    bool checkPunch(const Player *other);
};

#endif /* defined(__MOE__Player__) */
