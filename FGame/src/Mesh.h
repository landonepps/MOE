/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/20/2014
 *
 * Handles meshes. Uses .ply files.
*******************************************************************************/

#ifndef __MESH_H__
#define __MESH_H__

#include <iostream>
#include <string>
#include <vector>
#include "glm/glm.hpp"
#include "Image.h"
using namespace std;
// using namespace glm;

//-----------------------------------------------------------------------------
class Mesh {
 public:
    //Make a new mesh, with mesh data populated from the given file.
     Mesh(char const *filename, char const *texname);

    // Destroy this mesh.
     virtual ~Mesh();

    // Draw all the polygon faces in this mesh.
    void draw();

 private:
    unsigned int vertices;
    unsigned int normals;
    unsigned int faces;
    unsigned int texCoords;

    glm::vec4 *vList;
    glm::vec3 *nList;
    vector<unsigned int> *fList;
    glm::vec2 *tList;

    GLuint texture;

    int height, width;
};
//-----------------------------------------------------------------------------

#endif
