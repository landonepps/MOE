//
//  Environment.cpp
//  MOE
//
//  Created by Landon Epps on 2/23/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Environment.h"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtc/type_ptr.hpp"

Environment::Environment() {
    mesh = NULL;
}

Environment::~Environment() {
    delete mesh;
}

void Environment::loadEnv(const char *meshfile, const char *texfile) {
    mesh = new Mesh(meshfile, texfile);
    scl = glm::vec3(10, 10, 10);
    pos = glm::vec3(0, mesh->getDimensions().y * scl.y / 2.0, 0);
    rot = glm::vec3(-90, 0, 0);

}

glm::vec3 Environment::getDimensions(){
    return mesh->getDimensions();
}

void Environment::draw() {
    glPushMatrix();
    glm::mat4 trans;
    trans = glm::translate(trans, pos);
    trans = glm::scale(trans, scl);
    trans = glm::rotate(trans, rot.x, glm::vec3(1.0f, 0.0f, 0.0f));
    trans = glm::rotate(trans, rot.y, glm::vec3(0.0f, 1.0f, 0.0f));
    trans = glm::rotate(trans, rot.z, glm::vec3(0.0f, 0.0f, 1.0f));
    glMultMatrixf(glm::value_ptr(trans));
    
    mesh->draw();
    
    glPopMatrix();
}