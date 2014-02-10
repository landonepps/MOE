#ifndef _PLAYER_H_
    #define _PLAYER_H_
 
#include "Entity.h"
 
class Player : public Entity {
    public:
        Player(int health);
 
        bool OnLoad(char* File, int Width, int Height, int MaxFrames);
 
        void OnLoop();
 
        void OnRender(SDL_Surface* Surf_Display);
 
        void OnCleanup();
 
        void OnAnimate();
 
        void OnCollision(Entity* Entity);

	    int currentHealth;

		int maxHealth;
};
 
#endif /* PLAYER_H_ */