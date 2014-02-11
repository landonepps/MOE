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

class Player {
    int x, y, h, w;
    double xVel, yVel;
    Image img;
    Animation ani;
    SDL_Renderer *renderer;
    
public:
    Player();
    ~Player();
    void loadPlayer(const char *filename, SDL_Renderer *renderer);
    void update(Clock *clock);
    void punch();
    void draw();
};

#endif /* defined(__MOE__Player__) */
