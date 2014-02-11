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
    renderer = NULL;
    ani.maxFrames = 5;
}

Player::~Player() {
    
}

void Player::loadPlayer(const char *filename, SDL_Renderer *renderer) {
    img.loadImage(filename, renderer);
}

void Player::update(Clock *clock) {
    ani.OnAnimate(clock);
}

void Player::punch() {
    ani.maxFrames = 6;
    ani.setCurrentFrame(5);
}

void Player::walk() {
    ani.maxFrames = 5;
    ani.setCurrentFrame(0);
}

void Player::draw() {
    img.draw(x, y, 0, ani.getCurrentFrame() * h, w, h);
}