/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * Handles the camera
 *
 ******************************************************************************/

#include "Camera.h"

// #define GLM_FORCE_RADIANS

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Camera::Camera() {
    pos = glm::vec3(0, 0, 0);
    rot = glm::vec3(0, 0, 0);
    fov = 45;
    aspect = 4.0/3.0;
    zNear = 0.1;
    zFar = 30000;
}

Camera::~Camera() {
    
}

// multiply camera matrix using glMulMatrix
void Camera::multMatrix() {
    glm::mat4 trans;
    trans = glm::perspective(fov, aspect, zNear, zFar);
    trans = glm::rotate(trans, rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
    trans = glm::rotate(trans, rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::translate(trans, pos);

    glMultMatrixf(glm::value_ptr(trans));
}

// set camera position
void Camera::setPosition(glm::vec3 newPos) {
    this->pos = newPos;
}

// set camera rotation
void Camera::setRotation(glm::vec3 newRot) {
    this->rot = newRot;
}

// set camera fov
void Camera::setFov(GLfloat newFov) {
    this->fov = newFov;
}

// set camera apsect ratio
void Camera::setAspect(GLfloat newAspect) {
    this->aspect = newAspect;
}

// set minimum z draw
void Camera::setZNear(GLfloat newZNear) {
    this->zNear = newZNear;
}

// set max z draw
void Camera::setZFar(GLfloat newZFar) {
    this->zFar = newZFar;
}