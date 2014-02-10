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

#ifndef _ENTITYCOLLISION_H_
    #define _ENTITYCOLLISION_H_

#include <vector>
#include "Entity.h"

class EntityCollision {
    public:
        static std::vector<EntityCollision>    collisionList;
 
    public:
        Entity* entityA;
        Entity* entityB;
 
    public:
        EntityCollision();
};

#endif /* ENTITYCOLLISION_H_ */
