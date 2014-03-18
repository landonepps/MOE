/*******************************************************************************
*
* Author:      Jesse Clary
*
* Assignment:  MOE (Most Optimistic Engine)
* Class:       4342, Sprnt 2014
* Date:        2/8/2014
*
* Handles the images, animation, and collision for game characters
*
******************************************************************************/

#ifndef __MOE__Enemy__
#define __MOE__Enemy__

#include "Mesh.h"
#include "SFX.h"
#include "Physics2.h"
#include "Camera.h"
#include "SceneGraphNode.h"

class Enemy : public SceneGraphNode {
    Mesh *theMesh;
    SceneGraphNode *center;
    SceneGraphNode *left;
    SceneGraphNode *right;

    Physics2 physics;
    vector< pair<int, int> > stats;
    glm::vec3 enemyDimensions;
    glm::vec3 scale;
    int difficulty;
public:

    /*
    * Enemy: Constructor for Enemy
    */
    Enemy();

    /*
    * ~Enemy: Destructor for Enemy
    */
    ~Enemy();

    // set velocity for x and z
    void setVel(glm::vec3 newVel);
    // set velocity for y
    void setVelY(GLfloat yVel);
    // update Enemy physics
    void update();

    void setup(char const* filename, char const* texname);
    void setLocation(GLfloat x, GLfloat y, GLfloat z);
    void setScale(GLfloat sX, GLfloat sY, GLfloat sZ);
    void setDifficulty(int dif);

    void draw();
    glm::vec3 getPosition();
    glm::vec3 getDimensions();

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
    * checkCollision: checks if the Enemy has collided with an object based
    *                   on that object's center and dimensions. Returns true
    *                   if a collision occured.
    *
    * center: center point of the object to be checked against
    * dimensions: dimensions of the object to be checked against
    *
    * returns:   void.
    ***********************************************************************/
    bool checkCollision(glm::vec3 center, glm::vec3 dimensions);

    void runAI(glm::vec3);
};

#endif /* defined(__MOE__Enemy__) */
