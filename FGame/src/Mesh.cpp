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
#include <GL.h>
#include <GLU.h>
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
  vertices = NULL;
  faces    = NULL;

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
  vList = new Vector[vertices];
  nList = new Vector[normals];
  for(unsigned int vertex = 0; vertex < vertices; vertex++) {
    input >> vList[vertex].x;
    input >> vList[vertex].y;
    input >> vList[vertex].z;
    vList[vertex].w = 1;

    input >> nList[vertex].x;
    input >> nList[vertex].y;
    input >> nList[vertex].z;
    vList[vertex].w = 1;
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
}
//-----------------------------------------------------------------------------



//-----------------------------------------------------------------------------
void Mesh::draw() {
  for(unsigned int face = 0; face < faces; face++) {
    glBegin(GL_POLYGON);
    for(unsigned int vertex = 0; vertex < fList[face].size(); vertex++) {
      nList[fList[face][vertex]].glNormal();
      vList[fList[face][vertex]].glVertex();
    }
    glEnd();
  }
}
//-----------------------------------------------------------------------------
