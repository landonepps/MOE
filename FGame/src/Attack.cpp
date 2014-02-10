#include "Attack.h"
#include "Player.h"

Attack::Attack(int str) {
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
 
void Attack::OnLoop(Clock* clock) {
    Entity::OnLoop(clock);
}
 
void Attack::OnRender(SDL_Surface* surfDisplay) {
    Entity::OnRender(surfDisplay);
}

void Attack::OnAnimate(Clock* clock) {
    Entity::OnAnimate(clock);
}
 
void Attack::OnCollision(Entity* entity) {
	if(entity-> entType == ENTITY_TYPE_PLAYER) {
		((Player*) entity)->currentHealth -= strength;
	}
}
