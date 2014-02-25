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

void Player::addStat(int id, int val){
    stats.push_back(make_pair(id, val));
}

pair<int, int>* Player::getStatData(int i){
    return &stats[i];
}

bool Player::checkCollision(glm::vec3 center, glm::vec3 dimensions){
    glm::vec3 yes = glm::vec3(0, 0, 0);
    return physics.checkCollision(physics.getPos(), center, yes, dimensions);
}