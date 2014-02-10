#ifndef _ATTACK_H_
    #define _ATTACK_H_
 
#include "Entity.h"
 
class Attack : public Entity {
    public:
        Attack(int str = 5);
 
 
        void OnLoop(Clock* clock);
 
        void OnRender(SDL_Surface* Surf_Display);
 
        void OnAnimate(Clock *clock);
 
        void OnCollision(Entity* Entity);

    protected:
		int strength;
};
 
#endif /* ATTACK_H_ */