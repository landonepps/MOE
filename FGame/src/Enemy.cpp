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

#include "Enemy.h"
#include "Constants.h"
#include "glm/gtc/matrix_transform.hpp"
/*
* Enemy: Constructor for Enemy
*/
Enemy::Enemy() {
    enemyDimensions = glm::vec3(0, 0, 0);
}

/*
* ~Enemy: Destructor for Enemy
*/
Enemy::~Enemy() {
    delete theMesh;
}

void Enemy::setup(char const* filename, char const* texname)
{
    theMesh = new Mesh(filename, texname);
    glm::vec3 temp = theMesh->getDimensions();
    enemyDimensions = temp;
}

/***********************************************************************
* setTime:   Sets the location of the object
*
* x: x position
* y: y position
* z: z position
*
* returns:   void.
***********************************************************************/
void Enemy::setLocation(GLfloat x, GLfloat y, GLfloat z){
    physics.setPos(glm::vec3(x, y, z));
}

/***********************************************************************
* setScale:   Sets the scale of the object
*
* x: x scale
* y: y scale
* z: z scale
*
* returns:   void.
***********************************************************************/
void Enemy::setScale(GLfloat x, GLfloat y, GLfloat z){
    scale = glm::vec3(x, y, z);
}

void Enemy::setDifficulty(int dif){
    difficulty = dif;
}

/***********************************************************************
* draw:   Simply draws the Enemy to the screen with specified flags
*           to enable bobbing or rotating.
*
* returns:   void.
***********************************************************************/
void Enemy::draw(){
    glPushMatrix();
    glTranslatef(getPosition().x, getPosition().y, getPosition().z);
    glScalef(scale.x, scale.y, scale.z);
    glRotatef(-90, 1, 0, 0);
    theMesh->draw();
    glPopMatrix();
}

/***********************************************************************
* getPosition: returns a vec3 of the position of the object
*
* returns:   vec3
***********************************************************************/
glm::vec3 Enemy::getPosition(){
    return physics.getPos();
}

glm::vec3 Enemy::getDimensions(){
    return theMesh->getDimensions() * scale;
}

// set velocity for x and z
void Enemy::setVel(glm::vec3 newVel) {
    physics.setVel(newVel);
}

// set velocity for y
void Enemy::setVelY(GLfloat yVel) {
    physics.setVelY(yVel);
}

// update Enemy physics
void Enemy::update() {
    physics.update();
}

/***********************************************************************
* addStat: adds a a stat with an id and initial value.
*
* id: the id of the stat
* val: the value of the stat
*
* returns:   void.
***********************************************************************/
void Enemy::addStat(int id, int val){
    stats.push_back(make_pair(id, val));
}

/***********************************************************************
* getStatData: returns a stat with its id and value
*
* i: element to be dereferenced
*
* returns:   pair<int,int>*
***********************************************************************/
pair<int, int>* Enemy::getStatData(int i){
    return &stats[i];
}

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
bool Enemy::checkCollision(glm::vec3 center, glm::vec3 dimensions){
    bool collided = false;

    if (
        (physics.getPos().z) <= center.z + dimensions.z / 2 && (physics.getPos().x) >= center.x - dimensions.x / 2 &&
        (physics.getPos().x) <= center.x + dimensions.x / 2 && (physics.getPos().z) >= center.z - dimensions.z / 2 &&
        (physics.getPos().y) <= center.y + dimensions.y / 2 && (physics.getPos().y) >= center.y - dimensions.y / 2
        )
    {
        collided = true;
    }

    return collided;
}

void Enemy::runAI(glm::vec3 furniturePosition){
    glm::vec3 temp;
    temp = furniturePosition - getPosition();

    temp = glm::normalize(temp);

    temp *= glm::vec3(100, 100, 100);

    setVel(temp);
    setVelY(temp.y);

    update();
}