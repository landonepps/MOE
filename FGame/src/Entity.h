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

#ifndef _ENTITY_H_
    #define _ENTITY_H_
 
#include <vector>

#include "Animation.h"
#include "SpeedControl.h"
#include "Clock.h"

/** Values for entity typing **/
enum {
    ENTITY_TYPE_GENERIC = 0,
 
    ENTITY_TYPE_PLAYER,

	ENTITY_TYPE_ATTACK
};
 
/** Values for collision typing **/
enum {
    ENTITY_FLAG_NONE = 0,
 
    ENTITY_FLAG_GRAVITY    = 0x00000001,
    ENTITY_FLAG_THRU_WALL  = 0x00000002,
    ENTITY_FLAG_NO_COLLIDE = 0x00000004
};
 
class Entity {
    public:
		/** List of entities **/
        static std::vector<Entity*> entities;

		/** Current x and y locations **/
        float  xLoc;
        float  yLoc;
 
		/** Entity's width and height **/
        int    width;
        int    height;
 
		/** Whether the entity is moving left and/or right **/
        bool   moveLeft;
        bool   moveRight;

		/**The type of the entity **/
        int    entType;
 
		/** Whether the entity should still appear or not **/
        bool   isDead;
		/** What collision type is set **/
        int    flags;

		/** Max possible speed **/
        float  xSpdMax;
        float  ySpdMax;
    
        /** The entity's animation. **/
        Animation aniControl;
 
    protected:
		/** Current speed **/
        float  xSpd;
        float  ySpd;
 
		/** Current acceleration **/
        float  xAccel;
        float  yAccel;

		/** Current collision data */
        int    xCollision;
        int    yCollision;
        int    colWidth;
        int    colHeight;

		/** The col and row of the frame on the sprite sheet **/
        int    frameCol;
        int    frameRow;

	   
 
		/** The entity's surface **/
        SDL_Surface* surfEntity;
 
    public:
        Entity();

		Entity(Animation ani);
 
        virtual ~Entity();
 
        virtual void OnLoop(Clock* clock);
 
        virtual void OnRender(SDL_Surface* Surf_Display);
 
        virtual void OnAnimate(Clock* clock);
 
        virtual void OnCollision(Entity* Entity);

        void OnMove(float MoveX, float MoveY);
 
        void stop();

        bool collides(int oX, int oY, int oW, int oH);

		void setAnimation(Animation ani);
 
    private:

        bool    validPosition(int NewX, int NewY);
 
        //bool     PosValidTile(Tile* Tile);
 
        bool    validEntity(Entity* Entity, int NewX, int NewY);       
};
 
#endif /* ENTITY_H_ */