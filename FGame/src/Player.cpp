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

#include "Player.h"
#include "Constants.h"

/*
 * Player: Constructor for Player
 */
Player::Player() {
    cam = new Camera();
    playerDimensions = glm::vec3(0, 0, 0);
}

/*
 * ~Player: Destructor for Player
 */
Player::~Player() {
    delete cam;
}

void Player::setVel(glm::vec3 newVel) {
    physics.setVel(newVel);
}

void Player::setVelY(GLfloat yVel) {
    physics.setVelY(yVel);
}

void Player::setAVel(glm::vec3 newAVel) {
    physics.setAVel(newAVel);
}

void Player::update() {
    physics.update();
}

void Player::updateCamera() {
    cam->setPosition(physics.getPos());
    cam->setRotation(physics.getRot());
    cam->multMatrix();
}

/***********************************************************************
* addStat: adds a a stat with an id and initial value.
*
* id: the id of the stat
* val: the value of the stat
*
* returns:   void.
***********************************************************************/
void Player::addStat(int id, int val){
    stats.push_back(make_pair(id, val));
}

/***********************************************************************
* getStatData: returns a stat with its id and value
*
* i: element to be dereferenced
*
* returns:   pair<int,int>*
***********************************************************************/
pair<int, int>* Player::getStatData(int i){
    return &stats[i];
}

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
bool Player::checkCollision(glm::vec3 center, glm::vec3 dimensions){
    return physics.checkCollision(physics.getPos(), center, playerDimensions, dimensions);
}