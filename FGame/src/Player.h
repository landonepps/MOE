/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * Handles the images, animation, and collision for game characters
 *
 ******************************************************************************/

#ifndef __MOE__Player__
#define __MOE__Player__

#include "Mesh.h"
#include "SFX.h"
#include "Physics2.h"
#include "Camera.h"

class Player {
    Camera *cam;
    Physics2 physics;
    
public:
    
    /*
     * Player: Constructor for Player
     */
    Player();
    
    /*
     * ~Player: Destructor for Player
     */
    ~Player();
    
    void setVel(glm::vec3 newVel);
    void setAVel(glm::vec3 newAVel);
    
    void update();
    
    void updateCamera();
};

#endif /* defined(__MOE__Player__) */
