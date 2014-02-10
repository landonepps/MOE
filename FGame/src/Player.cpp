#include "Player.h"
 
Player::Player(int health = 100) {
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
 
bool Player::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    return Entity::OnLoad(File, Width, Height, MaxFrames);
}
 
void Player::OnLoop() {
    Entity::OnLoop();
}
 
void Player::OnRender(SDL_Surface* surfDisplay) {
    Entity::OnRender(surfDisplay);
}
 
void Player::OnCleanup() {
    Entity::OnCleanup();
}
 
void Player::OnAnimate() {
    Entity::OnAnimate();
}
 
void Player::OnCollision(Entity* entity) {
}
