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