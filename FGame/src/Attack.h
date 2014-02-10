#ifndef _ATTACK_H_
    #define _ATTACK_H_
 
#include "Entity.h"
 
class Attack : public Entity {
    public:
        Attack(int str);
 
        bool OnLoad(char* File, int Width, int Height, int MaxFrames);
 
        void OnLoop(Clock* clock);
 
        void OnRender(SDL_Surface* Surf_Display);
 
        void OnCleanup();
 
        void OnAnimate(Clock *clock);
 
        void OnCollision(Entity* Entity);

    protected:
		int strength;
};
 
#endif /* ATTACK_H_ */