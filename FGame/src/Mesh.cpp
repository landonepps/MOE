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

#include "Mesh.h"
#ifdef _MSC_VER
#include <SDL.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#include <SDL_image.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <SDL2/SDL.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#endif
#include <fstream>
#include <string>
#include <iostream>
#include <algorithm>

#ifndef GL_BGR_EXT
#define GL_BGR_EXT 0x80E0
#endif

#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80E1
#endif

using namespace std;

/***********************************************************************
* Mesh: mesh constructor
*
* filename: mesh file name
* texname: texture file name
*
* returns:   void.
***********************************************************************/
Mesh::Mesh(const char *filename, const char *texname ) {
    SDL_Surface* surface = IMG_Load(texname);
    SDL_PixelFormat pf;
    pf.format = SDL_PIXELFORMAT_RGBA4444;
    pf.palette = NULL;
    pf.BitsPerPixel = 32;
    pf.BytesPerPixel = 4;
    pf.Rmask = 0x00ff0000;
    pf.Gmask = 0x0000ff00;
    pf.Bmask = 0x000000ff;
    pf.Amask = 0x00000000;
    surface = SDL_ConvertSurface(surface, &pf, 0);
    
    texture = 0;
    
    glGenTextures(1, &texture);
    
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surface->w, surface->h, 0, GL_BGRA_EXT, GL_UNSIGNED_BYTE, surface->pixels);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    
    SDL_FreeSurface(surface);

    vertices = 0;
    faces    = 0;
    
    //Append mesh and fead from the file.
    ifstream input( ( string( filename ) ).c_str(), ios::binary );
    
    //Verify that file is ply format.
    string str = "";
    input >> str;
    if(str != "ply") {
        cout << "ERROR: Wrong mesh format." << endl;
        exit(1);
    }
    
    //Find element vertex in header.
    while(str != "vertex") {
        str.clear();
        input >> str;
        
        if(str.empty()) {
            cout << "ERROR: Can't find element vertex." << endl;
            exit(1);
        }
    }
    
    //Get the number of vertices.
    input >> vertices;
    normals = vertices;
    texCoords = vertices;
    
    //Find element face in header.
    while(str != "face") {
        str.clear();
        input >> str;
        
        if(str.empty()) {
            cout << "ERROR: Can't find element face." << endl;
            exit(1);
        }
    }
    
    // Get the number of faces.
    input >> faces;
    
    //Get to the end of the header.
    while(str != "end_header") {
        str.clear();
        input >> str;
        
        if(str.empty()) {
            cout << "ERROR: Can't find end of header." << endl;
            exit(1);
        }
    }
    
    min = glm::vec3(0, 0, 0);
    max = glm::vec3(0, 0, 0);

    hitbox = false;

    //Read in vertices and normals.
    vList = new glm::vec4[vertices];
    nList = new glm::vec3[normals];
    tList = new glm::vec2[texCoords];
    for(unsigned int vertex = 0; vertex < vertices; vertex++) {
        
        /** Read in vertices. **/
        input >> vList[vertex].x;
        input >> vList[vertex].y;
        input >> vList[vertex].z;
        vList[vertex].w = 1;
        
        if (vList[vertex].x > max.x){ max.x = vList[vertex].x; }
        if (vList[vertex].y > max.y){ max.y = vList[vertex].y; }
        if (vList[vertex].z > max.z){ max.z = vList[vertex].z; }

        if (vList[vertex].x < min.x){ min.x = vList[vertex].x; }
        if (vList[vertex].y < min.y){ min.y = vList[vertex].y; }
        if (vList[vertex].z < min.z){ min.z = vList[vertex].z; }

        /** Read in normals. **/
        input >> nList[vertex].x;
        input >> nList[vertex].y;
        input >> nList[vertex].z;
        vList[vertex].w = 1;
        
        /** Read in texture coordinates. **/
        input >> tList[vertex].x;
        input >> tList[vertex].y;
    }
    
    dimensions.x = abs(max.x) + abs(min.x);
    dimensions.y = abs(max.y) + abs(min.y);
    dimensions.z = abs(max.z) + abs(min.z);

    //Read in faces.
    fList = new vector<unsigned int>[faces];
    for(unsigned int face = 0; face < faces; face++) {
        
        // Get the total number of vertices in the face and read them in.
        int numVertices = 0;
        input >> numVertices;
        
        //Read in each set of vertices.
        for(int vertex = 0; vertex < numVertices; vertex++) {
            unsigned int theVertex;
            input >> theVertex;
            fList[face].push_back(theVertex);
        }
    }
}


Mesh::~Mesh() {
    delete [] vList;
    delete [] nList;
    delete [] fList;
    delete [] tList;
    glDeleteTextures(1, &texture);
}

/***********************************************************************
* draw: draws the mesh to the screen along with the texture also draws
*           the hitbox if it is enabled
*
*
* returns:   void.
***********************************************************************/
void Mesh::draw() {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    for (unsigned int face = 0; face < faces; face++) {
        glBegin(GL_POLYGON);
        for (unsigned int vertex = 0; vertex < fList[face].size(); vertex++) {
            glm::vec3 norm = nList[fList[face][vertex]];
            glNormal3d(norm.x, norm.y, norm.z);
            glm::vec2 tex = tList[fList[face][vertex]];
            glTexCoord2f(tex.x, -tex.y);
            glm::vec4 vtx = vList[fList[face][vertex]];
            glVertex4d(vtx.x, vtx.y, vtx.z, vtx.w);
        }
        glEnd();
    }

    if (hitbox){
        glBegin(GL_LINE_STRIP);
        glVertex3f(min.x, min.y, min.z);
        glVertex3f(max.x, min.y, min.z);
        glVertex3f(max.x, max.y, min.z);
        glVertex3f(min.x, max.y, min.z);
        glVertex3f(min.x, min.y, min.z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex3f(min.x, min.y, max.z);
        glVertex3f(max.x, min.y, max.z);
        glVertex3f(max.x, max.y, max.z);
        glVertex3f(min.x, max.y, max.z);
        glVertex3f(min.x, min.y, max.z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex3f(min.x, min.y, min.z);
        glVertex3f(max.x, min.y, min.z);
        glVertex3f(max.x, min.y, max.z);
        glVertex3f(min.x, min.y, max.z);
        glVertex3f(min.x, min.y, min.z);
        glEnd();

        glBegin(GL_LINE_STRIP);
        glVertex3f(min.x, max.y, max.z);
        glVertex3f(max.x, max.y, max.z);
        glVertex3f(max.x, max.y, min.z);
        glVertex3f(min.x, max.y, min.z);
        glVertex3f(min.x, max.y, max.z);
        glEnd();
    }

    glDisable(GL_TEXTURE_2D);
}
/***********************************************************************
* getDimensions: returns the mesh's dimensions
*
*
* returns:   glm::vec3
***********************************************************************/
glm::vec3 Mesh::getDimensions(){
    return dimensions;
}
/***********************************************************************
* setHitbox: toggles the show hitbox bool
* 
* bool: hit is true to set hitboxes, false otherwise
*
* returns:   void.
***********************************************************************/
void Mesh::setHitbox(bool hit){
    hitbox = hit;
}
