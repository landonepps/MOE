/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * Handles the images, animation, and collision for game characters
 *
 ******************************************************************************/

#ifndef __MOE__Player__
#define __MOE__Player__

#include "Image.h"
#include "Animation.h"
#include "SFX.h"

class Player {
    // position and size
    int x, y, h, w;
    // velocity
    double xVel, yVel;
    // player image sprite
    Image img;
    // animation handler
    Animation ani;
    // renderer pointer
    SDL_Renderer *renderer;
    // punch sound SFX
    SFX punchSound;
    // health value
    float health;
    
    /* will remove later */
    // keep track of whether player is in walking animation
    bool walking;
    
public:
    
    /*
     * Player: Constructor for Player
     */
    Player();
    
    /*
     * ~Player: Destructor for Player
     */
    ~Player();
    
    /*
     * loadPlayer: sets the starting values and loads media for a Player
     *
     * image: path to image file (.jpg/png)
     * attack: path to attack SFX (.wav)
     * renderer: pointer to the renderer object
     * x: starting x coordinate
     * y: starting y coordinate
     *
     * returns: void
     */
    void loadPlayer(const char *image, const char *attack, SDL_Renderer *renderer, int x, int y);
    
    /*
     * update: refreshes Player animation and position
     *
     * clock: pointer to main game clock
     */
    void update(Clock *clock);
    
    /*
     * punch: runs punch animation and plays attack sound
     */
    void punch();
    
    /*
     * walk: runs walk animation
     */
    void walk();
    
    /*
     * moveLeft: sets x velocity for moving left
     */
    void moveLeft();
    
    /*
     * moveRight: sets x velocity for moving right
     */
    void moveRight();
    
    /*
     * halt: sets all velocity to 0
     */
    void halt();
    
    /*
     * draw: draws player to the renderer using specified position and animation frame
     */
    void draw();
    
    /*
     * getHealth: returns current player health
     */
    float getHealth();
    
    /*
     * checkPlayerCollision: checks collition with another player
     *
     * other: player with which to check collision
     *
     * returns: true if collision detected
     */
    bool checkPlayerCollision(const Player *other);
    
    /*
     * checkPunch: checks punch collition with another player
     *
     * other: player with which to check punch collision
     *
     * returns: true if punch collision detected
     */
    bool checkPunch(Player *other);
    
    /*
     * checkWallCollision: checks collition with screen border
     *
     * returns: true if collision detected
     */
    bool checkWallCollision();
};

#endif /* defined(__MOE__Player__) */
