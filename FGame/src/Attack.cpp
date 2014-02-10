#include "Attack.h"
#include "Player.h"

Attack::Attack(int str = 5) {
    surfEntity = NULL;
 
    xLoc = 0;
    yLoc = 0;
 
    width  = 0;
    height = 0;
 
    moveLeft  = false;
    moveRight = false;

    entType = ENTITY_TYPE_ATTACK;
 
    isDead = false;
    flags = ENTITY_FLAG_THRU_WALL;
 
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

	strength = str;
}
 
bool Attack::OnLoad(char* File, int Width, int Height, int MaxFrames) {
    return Entity::OnLoad(File, Width, Height, MaxFrames);
}
 
void Attack::OnLoop() {
    Entity::OnLoop();
}
 
void Attack::OnRender(SDL_Surface* surfDisplay) {
    Entity::OnRender(surfDisplay);
}
 
void Attack::OnCleanup() {
    Entity::OnCleanup();
}
 
void Attack::OnAnimate() {
    Entity::OnAnimate();
}
 
void Attack::OnCollision(Entity* entity) {
	if(entity-> entType == ENTITY_TYPE_PLAYER) {
		((Player*) entity)->currentHealth -= strength;
	}
}
