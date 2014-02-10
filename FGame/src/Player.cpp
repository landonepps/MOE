#include "Player.h"
 
Player::Player() {
    surfEntity = NULL;
 
    xLoc = 0;
    yLoc = 0;
 
    width  = 0;
    height = 0;
 
    moveLeft  = false;
    moveRight = false;

    entType = ENTITY_TYPE_PLAYER;
 
    isDead = false;
    flags = ENTITY_FLAG_GRAVITY;
 
    xSpd = 0;
    ySpd= 0;
 
    xAccel = 0;
    yAccel = 0;
 
    xSpdMax = 5;
    ySpdMax = 5;
 
    frameCol = 0;
    frameRow = 0;
 
    xCollision = 0;
    yCollision = 0;
 
    colWidth  = 0;
    colHeight = 0;

	currentHealth = 100;
	maxHealth = 100;
}

Player::Player(int health) {
    surfEntity = NULL;
 
    xLoc = 0;
    yLoc = 0;
 
    width  = 0;
    height = 0;
 
    moveLeft  = false;
    moveRight = false;

    entType = ENTITY_TYPE_PLAYER;
 
    isDead = false;
    flags = ENTITY_FLAG_GRAVITY;
 
    xSpd = 0;
    ySpd= 0;
 
    xAccel = 0;
    yAccel = 0;
 
    xSpdMax = 5;
    ySpdMax = 5;
 
    frameCol = 0;
    frameRow = 0;
 
    xCollision = 0;
    yCollision = 0;
 
    colWidth  = 0;
    colHeight = 0;

	currentHealth = health;
	maxHealth = health;
}
 
void Player::OnLoop(Clock* clock) {
    Entity::OnLoop(clock);
}
 
void Player::OnRender(SDL_Surface* surfDisplay) {
    Entity::OnRender(surfDisplay);
}
 
void Player::OnAnimate(Clock *clock) {
    Entity::OnAnimate(clock);
}
 
void Player::OnCollision(Entity* entity) {
}