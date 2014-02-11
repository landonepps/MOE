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

#include "Player.h"

Player::Player() {
    x = 70;
    y = 200;
    h = 200;
    w = 140;
    xVel = 0;
    yVel = 0;
    renderer = NULL;
    ani.firstFrame = 0;
    ani.lastFrame = 4;
    
    // bool moveRight = false;
    
    walking = true;
}

Player::~Player() {
    
}

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

void Player::update(Clock *clock) {
    ani.OnAnimate(clock);
    x += xVel * clock->getTimeScale();
    y += yVel * clock->getTimeScale();
}

void Player::punch() {
    walking = false;
    punchSound.play();
    ani.firstFrame = 5;
    ani.lastFrame = 5;
    ani.setCurrentFrame(5);
}

void Player::walk() {
    if (!walking) {
        ani.firstFrame = 0;
        ani.lastFrame = 4;
        ani.setCurrentFrame(0);
        walking = true;
    }
}

void Player::moveLeft() {
    xVel = 3.0;
}

void Player::moveRight() {
    xVel = -3.0;
}

void Player::halt() {
    xVel = yVel = 0;
}

void Player::draw() {
    img.draw(x, y, 0, ani.getCurrentFrame() * h, w, h);
}

bool Player::checkCollision(const Player *other) {
    bool result = false;
    if () {
        result = true;
        x -= xVel;
        halt();
    } else if () {
        result = true;
        x -= xVel;
        halt();
    }
    
    return result;
}

bool Player::checkPunch(const Player *other) {
    return false;
}