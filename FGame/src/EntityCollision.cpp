/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/09/2014
 *
 * Lists in-game entity collisions.
*******************************************************************************/

#include "EntityCollision.h"

std::vector<EntityCollision> EntityCollision::collisionList;
 
EntityCollision::EntityCollision() {
    entityA = NULL;
    entityB = NULL;
}