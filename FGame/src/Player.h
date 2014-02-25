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
#include "Environment.h"

class Player {
    Camera *cam;
    Physics2 physics;
    vector< pair<int,int>> stats;
    glm::vec3 playerDimensions;
public:
    
    /*
     * Player: Constructor for Player
     */
    Player();
    
    /*
     * ~Player: Destructor for Player
     */
    ~Player();
    
    // set velocity for x and z
    void setVel(glm::vec3 newVel);
    // set velocity for y
    void setAVel(glm::vec3 newAVel);
    // set angular velocity
    void setVelY(GLfloat yVel);
    // update player physics
    void update();
    // change camera settings to player physics
    void updateCamera();

    /***********************************************************************
     * addStat: adds a a stat with an id and initial value.
     *
     * id: the id of the stat
     * val: the value of the stat
     *
     * returns:   void.
     ***********************************************************************/
    void addStat(int id, int amount);

    /***********************************************************************
     * getStatData: returns a stat with its id and value
     *
     * i: element to be dereferenced
     *
     * returns:   pair<int,int>*
     ***********************************************************************/
    pair<int, int>* getStatData(int i);

    /***********************************************************************
     * checkCollision: checks if the player has collided with an object based
     *                   on that object's center and dimensions. Returns true
     *                   if a collision occured.
     *
     * center: center point of the object to be checked against
     * dimensions: dimensions of the object to be checked against
     *
     * returns:   void.
     ***********************************************************************/
    bool checkCollision(glm::vec3 center, glm::vec3 dimensions);
};

#endif /* defined(__MOE__Player__) */
