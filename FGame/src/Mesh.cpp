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


using namespace std;

//-----------------------------------------------------------------------------
Mesh::Mesh( char const *filename ) {
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
    
    //Read in vertices and normals.
    vList = new glm::vec4[vertices];
    nList = new glm::vec3[normals];
    tList = new pair<float, float>[texCoords];
    for(unsigned int vertex = 0; vertex < vertices; vertex++) {
        
        /** Read in vertices. **/
        input >> vList[vertex].x;
        input >> vList[vertex].y;
        input >> vList[vertex].z;
        vList[vertex].w = 1;
        
        /** Read in normals. **/
        input >> nList[vertex].x;
        input >> nList[vertex].y;
        input >> nList[vertex].z;
        vList[vertex].w = 1;
        
        /** Read in texture coordinates. **/
        input >> tList[vertex].first;
        input >> tList[vertex].second;
        
        //tList[vertex].first = (tList[vertex].first + 1) / 2;
        //tList[vertex].first = (tList[vertex].second + 1) / 2;
    }
    
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
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
Mesh::~Mesh() {
    delete [] vList;
    delete [] nList;
    delete [] fList;
    delete [] tList;
}
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
void Mesh::draw() {
    for(unsigned int face = 0; face < faces; face++) {
        glBegin(GL_POLYGON);
        for(unsigned int vertex = 0; vertex < fList[face].size(); vertex++) {
            glm::vec3 norm = nList[fList[face][vertex]];
            glNormal3d(norm.x, norm.y, norm.z);
            glTexCoord2f(tList[vertex].first, tList[vertex].second);
            glm::vec4 vtx = vList[fList[face][vertex]];
            glVertex4d(vtx.x, vtx.y, vtx.z, vtx.w);
        }
        glEnd();
    }
}
//-----------------------------------------------------------------------------
