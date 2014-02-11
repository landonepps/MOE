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

#include "Player.h"
#include "Constants.h"

/*
 * Player: Constructor for Player
 */
Player::Player() {
    // hard-coded default values for demo purposes only
    x = 70;
    y = 200;
    h = 200;
    w = 130;
    xVel = 0;
    yVel = 0;
    renderer = NULL;
    ani.firstFrame = 0;
    ani.lastFrame = 4;
    health = 100;
    
    walking = true;
}

/*
 * ~Player: Destructor for Player
 */
Player::~Player() {
    
}

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
void Player::loadPlayer(const char *image,
                        const char *attack,
                        SDL_Renderer *renderer,
                        int x,
                        int y) {
    this->x = x;
    this->y = y;
    img.loadImage(image, renderer);
    punchSound.loadSFX(attack);
}

/*
 * update: refreshes Player animation and position
 *
 * clock: pointer to main game clock
 */
void Player::update(Clock *clock) {
    ani.OnAnimate(clock);
    x += xVel * clock->getTimeScale();
    y += yVel * clock->getTimeScale();
}

/*
 * punch: runs punch animation and plays attack sound
 */
void Player::punch() {
    walking = false;
    punchSound.play();
    ani.firstFrame = 5;
    ani.lastFrame = 5;
    ani.setCurrentFrame(5);
}

/*
 * walk: runs walk animation
 */
void Player::walk() {
    if (!walking) {
        ani.firstFrame = 0;
        ani.lastFrame = 4;
        ani.setCurrentFrame(0);
        walking = true;
    }
}

/*
 * moveLeft: sets x velocity for moving left
 */
void Player::moveLeft() {
    xVel = -3.0;
}

/*
 * moveRight: sets x velocity for moving right
 */
void Player::moveRight() {
    xVel = 3.0;
}

/*
 * halt: sets all velocity to 0
 */
void Player::halt() {
    xVel = yVel = 0;
}

/*
 * draw: draws player to the renderer using specified position and animation frame
 */
void Player::draw() {
    img.draw(x, y, 0, ani.getCurrentFrame() * h, w, h);
}

/*
 * getHealth: returns current player health
 */
float Player::getHealth() {
    return health;
}

/*
 * checkPlayerCollision: checks collition with another player
 *
 * other: player with which to check collision
 *
 * returns: true if collision detected
 */
bool Player::checkPlayerCollision(const Player *other) {
    bool result = false;
    if (x < (other->x + other->w - PUNCH_REACH) && (x + w - PUNCH_REACH) > other->x) {
        result = true;
        x -= xVel;
        halt();
    } else if (x + w - PUNCH_REACH < (other->x) && x > (other->x + other->w - PUNCH_REACH)) {
        result = true;
        x -= xVel;
        halt();
    }
    
    return result;
}

/*
 * checkPunch: checks punch collition with another player
 *
 * other: player with which to check punch collision
 *
 * returns: true if punch collision detected
 */
bool Player::checkPunch(Player *other) {
    
    bool result = false;
    if (x < (other->x + other->w + PUNCH_REACH) && (x + w + PUNCH_REACH) > other->x) {
        result = true;
    } else if (x + w + PUNCH_REACH < (other->x) && x > (other->x + other->w + PUNCH_REACH)) {
        result = true;
    }
    
    if (result) {
        if (other->health - PUNCH_DMG < 0) {
            other->health = 0;
        } else {
            other->health -= PUNCH_DMG;
        }
    }
    
    return result;
}

/*
 * checkWallCollision: checks collition with screen border
 *
 * returns: true if collision detected
 */
bool Player::checkWallCollision() {
    bool result = false;
    if (x + w > WIN_WIDTH) {
        result = true;
        x -= xVel;
        halt();
    } else if (x < 0) {
        result = true;
        x -= xVel;
        halt();
    }
    return result;
}
