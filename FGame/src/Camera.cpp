//
//  Camera.cpp
//  MOE
//
//  Created by Landon Epps on 2/22/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Camera.h"

#define GLM_FORCE_RADIANS

#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Camera::Camera() {
#warning default values, change later
    pos = glm::vec3(0, 0, 0);
    rot = glm::vec3(glm::pi<float>()/2, 0, 0);
    fov = 100;
    aspect = 4.0/3.0;
    zNear = 0.1;
    zFar = 5000;
}

Camera::~Camera() {
    
}

void Camera::multMatrix() {
    glm::mat4 trans;
    
    trans = glm::perspective(fov, aspect, zNear, zFar);
    trans = glm::rotate(trans, rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
    trans = glm::rotate(trans, rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
    trans = glm::translate(trans, pos);

    glMultMatrixf(glm::value_ptr(trans));
}

void Camera::setPosition(glm::vec3 newPos) {
    this->pos = newPos;
}

void Camera::setRotation(glm::vec3 newRot) {
    this->rot = newRot;
}

void Camera::setFov(GLfloat newFov) {
    this->fov = newFov;
}

void Camera::setAspect(GLfloat newAspect) {
    this->aspect = newAspect;
}

void Camera::setZNear(GLfloat newZNear) {
    this->zNear = newZNear;
}

void Camera::setZFar(GLfloat newZFar) {
    this->zFar = newZFar;
}