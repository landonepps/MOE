/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/09/2014
 *
 * Handles in-game entities.
*******************************************************************************/

#include "Entity.h"
#include "EntityCollision.h"

std::vector<Entity*> Entity::entities;
 
Entity::Entity() {
    surfEntity = NULL;
 
    xLoc = 0;
    yLoc = 0;
 
    width  = 0;
    height = 0;
 
    moveLeft  = false;
    moveRight = false;

    entType = ENTITY_TYPE_GENERIC;
 
    isDead = false;
    flags = 0; //ENTITY_FLAG_GRAVITY;
 
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
}

Entity::Entity(Animation ani) {
    surfEntity = NULL;
 
    xLoc = 0;
    yLoc = 0;
 
    width  = 0;
    height = 0;
 
    moveLeft  = false;
    moveRight = false;

    entType = ENTITY_TYPE_GENERIC;
 
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

	aniControl = ani;
}

Entity::~Entity(){}

void Entity::OnLoop(Clock* clock) {
    //We're not Moving
    if(moveLeft == false && moveRight == false) {
        stop();
    }
 
    if(moveLeft) {
        xAccel = -0.5;
    }
	else if(moveRight) {
        xAccel = 0.5;
    }
 
    if(flags & ENTITY_FLAG_GRAVITY) {
        yAccel = 0.75f;
    }
 
    xSpd += xAccel * SpeedControl::FPSCorrection.getFactor();
    ySpd += yAccel * SpeedControl::FPSCorrection.getFactor();
 
    if(xSpd > xSpdMax) {
		xSpd =  xSpdMax;
	}
    if(xSpd < -xSpdMax) {
		xSpd = -xSpdMax;
	}
    if(ySpd > ySpdMax) {  
		ySpd =  ySpdMax;
	}
    if(ySpd < -ySpdMax) {
		ySpd = -ySpdMax;
	}
 
    //OnAnimate(clock);
    OnMove(xSpd, ySpd);
}
	
void Entity::OnRender(SDL_Surface* surfDisplay) {
    /**?*/
}

void Entity::OnAnimate(Clock* clock) {
    aniControl.OnAnimate(clock);
}

void Entity::OnCollision(Entity* entity) {
    /** Do Nothing (pure virtual). **/
}

void Entity::OnMove(float moveX, float moveY) {
    if(moveX == 0 && moveY == 0) {
		return;
	}
 
	/** Destination relative to current location **/
    double xOffset = 0;
    double yOffset = 0;
 
	//Correct movement for FPS
    moveX *= SpeedControl::FPSCorrection.getFactor();
    moveY *= SpeedControl::FPSCorrection.getFactor();
 
	//Calculate desired offset for x
    if(moveX != 0) {
        if(moveX >= 0) {
			xOffset =  SpeedControl::FPSCorrection.getFactor();
		}
	    else {
			xOffset = -SpeedControl::FPSCorrection.getFactor();
		}
    }
 
	//Calculate desired offset for y
    if(moveY != 0) {
        if(moveY >= 0) {
			yOffset =  SpeedControl::FPSCorrection.getFactor();
		}
        else {
			yOffset = -SpeedControl::FPSCorrection.getFactor();
		}
    }
 
    while(true) {
		//Always allow movement if thru walls is enabled
        if(flags & ENTITY_FLAG_THRU_WALL) {
			//Update collisions
            validPosition((int)(xLoc + xOffset), (int)(yLoc + yOffset)); 
            xLoc += xOffset;
            yLoc += yOffset;
        }
		else {
			//Move if able
            if(validPosition((int)(xLoc + xOffset), (int)(yLoc))) {
                xLoc += xOffset;
            }
			//Stop if movement is invalid
			else {
                xSpd = 0;
            }

            //Move if able
            if(validPosition((int)(xLoc), (int)(yLoc + yOffset))) {
                yLoc += yOffset;
            }
			//Stop if movement is invalid
			else{
                ySpd = 0;
            }
        }
 
        moveX += -xOffset;
        moveY += -yOffset;
 
		//Reset offsets
        if(xOffset > 0 && moveX <= 0) {
			xOffset = 0;
		}
        if(xOffset < 0 && moveX >= 0) {
			xOffset = 0;
		}
 
        if(yOffset > 0 && moveY <= 0) {
			yOffset = 0;
		}
        if(yOffset < 0 && moveY >= 0) {
			yOffset = 0;
		}
 
		//Check for destination reached
        if(moveX == 0) {
			xOffset = 0;
		}
        if(moveY == 0) {
			yOffset = 0;
		}
 
		//Check for finished movement
        if(moveX == 0 && moveY == 0) {
			break;
		}
        if(xOffset == 0 && yOffset == 0) {
			break;
		}
    }
}

void Entity::stop() {
	//Reverse acceleration
    if(xSpd > 0) {
        xAccel = -1;
	}
    if(xSpd < 0) {
        xAccel =  1;
    }
 
	//Determine a stop speed
    if(xSpd < 2.0f && xSpd > -2.0f) {
        xAccel = 0;
        xSpd = 0;
    }
}

bool Entity::collides(int bX, int bY, int bW, int bH) {

	/** Hit box definitions for objects a and b **/
    int left1, left2;
    int right1, right2;
    int top1, top2;
    int bottom1, bottom2;
 
	/** Object a's far left and top values **/
    int aX = xLoc + xCollision;
    int aY = yLoc + yCollision;
 
    left1 = aX;
    left2 = bX;
 
    right1 = left1 + width - 1 - colWidth;
    right2 = bX + bW - 1;
 
    top1 = aY;
    top2 = bY;
 
    bottom1 = top1 + height - 1 - colHeight;
    bottom2 = bY + bH - 1;
 
    //Check for collision
    if (bottom1 < top2) {
		return false;
	}
    if (top1 > bottom2) {
		return false;
	}
    if (right1 < left2) {
		return false;
	}
    if (left1 > right2) {
		return false;
	}
 
    return true;
}

bool Entity::validPosition(int newX, int newY) {
	/** Valid position flag **/
    bool retVal = true;
 
	//Eventually must account for TILE_SIZE
    int startX   = (newX + xCollision);
    int startY   = (newY + yCollision);
 
    int destX    = ((newX + xCollision) + width - colWidth - 1);
    int destY    = ((newY + yCollision) + height - colHeight - 1);
 
	/*
    for(int iY = startY; iY <= destY; iY++) {
        for(int iX = startX; iX <= destX; iX++) {
            CTile* Tile = CArea::AreaControl.GetTile(iX * TILE_SIZE, iY * TILE_SIZE);
 
            if(PosValidTile(Tile) == false) {
                Return = false;
            }
        }
    }
    */ 

    if(!(flags & ENTITY_FLAG_NO_COLLIDE)) {
        for(int i = 0; i < entities.size(); i++) {
            if(validEntity(entities[i], newX, newY) == false) {
                retVal = false;
            }
        }
    }
 
    return retVal;
}

bool Entity::validEntity(Entity* entity, int newX, int newY) {
    if(this != entity && entity != NULL && entity->isDead == false &&
        entity->flags ^ ENTITY_FLAG_NO_COLLIDE &&
        entity->collides(newX + xCollision, newY + yCollision, width - colWidth - 1, height - colHeight - 1) == true) {
 
        EntityCollision hit;
 
        hit.entityA = this;
        hit.entityB = entity;
 
        EntityCollision::collisionList.push_back(hit);
 
        return false;
    }
 
    return true;
}

void Entity::setAnimation(Animation ani) {
	aniControl = ani;
}