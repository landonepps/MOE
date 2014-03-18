/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       3/17/2014
 *
 * Handles terrain. Basic implementation created with help from thecplusplusguy.
 *******************************************************************************/

#include <iostream>
#include <cmath>

#ifdef _MSC_VER
#include <SDL.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#include <SDL_image.h>

#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <SDL2_image/SDL_image.h>

#else
#include <SDL2/SDL.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <SDL2/SDL_image.h>
#endif

#include "Terrain.h"

//Make a default terrain
Terrain::Terrain() {
    pos = glm::vec3(0,0,0);
    horScale = vertScale = 100;
}

//Make a terrain at 0,0,0 with scales hs and vs
Terrain::Terrain(float hs, float vs) {
    pos = glm::vec3(0,0,0);
    horScale = hs;
    vertScale = vs;
}

//Make a terrain at position p of scales hs and vs
Terrain::Terrain(glm::vec3 p, float hs, float vs) {
    pos = p;
    horScale = hs;
    vertScale = vs;
}

//Computes a normal vector
glm::vec3 Terrain::computeNormal(double h1, double h2, double h3, double h4) {
    glm::vec3 p1(0,h1,0);
    glm::vec3 p2(0,h2,1);
    glm::vec3 p3(1,h3,1);
    glm::vec3 p4(1,h4,0);
    
    glm::vec3 n;
    
    n.x =
    ( p1.y - p2.y ) * ( p1.z + p2.z ) +
    ( p2.y - p3.y ) * ( p2.z + p3.z ) +
    ( p3.y - p4.y ) * ( p3.z + p4.z ) +
    ( p4.y - p1.y ) * ( p4.z + p1.z );
    n.y =
    ( p1.z - p2.z ) * ( p1.x + p2.x ) +
    ( p2.z - p3.z ) * ( p2.x + p3.x ) +
    ( p3.z - p4.z ) * ( p3.x + p4.x ) +
    ( p4.z - p1.z ) * ( p4.x + p1.x );
    n.z =
    ( p1.x - p2.x ) * ( p1.y + p2.y ) +
    ( p2.x - p3.x ) * ( p2.y + p3.y ) +
    ( p3.x - p4.x ) * ( p3.y + p4.y ) +
    ( p4.x - p1.x ) * ( p4.y + p1.y );
    
    //n.x /= sqrt(x*x+y*y+z*z);
    //n.y /= sqrt(x*x+y*y+z*z);
    //n.z /= sqrt(x*x+y*y+z*z);
    
    return n;
}

//Loads the terrain
void Terrain::load(const char* file) {
    
    //Load the map
	SDL_Surface* map = SDL_LoadBMP(file);
	
    //Verify load
    if(!map) {
        cout << "ERROR: Terrain load failed." << endl;
		exit(1);
	}
    
    vector<float> temp;
    
    //Load the heights
	for(int i = 0; i < map->h; i++) {
		temp.clear();
        
		for(int j = 0; j < map->w; j++) {
			Uint32 loc = ((Uint32*)map->pixels)[i * map->pitch/4 + j];
            
			Uint8 r,g,b;
            
			SDL_GetRGB(loc, map->format, &r, &g, &b);
            
			temp.push_back((float)r/255.0);
		}
		heights.push_back(temp);
	}
	
    //Compute the normals
    for(int x = 0; x < heights.size()-1; x++) {
    	for(int z = 0; z < heights[0].size()-1; z++) {
    	    double h1 = heights[x][z];
    	    double h2 = heights[x+1][z];
    	    double h3 = heights[x+1][z+1];
    	    double h4 = heights[x][z+1];
    	    
    	    //normals[x*heights[0].size()+z] = computeNormal(h1, h2, h3, h4);
    	}
    }
}

//Renders the terrain
void Terrain::render() {
    glBegin(GL_QUADS);
	for(int i = 0; i < heights.size()-1; i++) {
		for(int j = 0; j < heights[0].size()-1; j++) {
            //Draw the terrain
            glVertex3f(pos.x+(i+1)*horScale, pos.y+heights[i+1][j]*vertScale, pos.z+j*horScale);
            glVertex3f(pos.x+i*horScale, pos.y+heights[i][j]*vertScale, pos.z+j*horScale);
            glVertex3f(pos.x+i*horScale, pos.y+heights[i][j+1]*vertScale, pos.z+(j+1)*horScale);
            glVertex3f(pos.x+(i+1)*horScale, pos.y+heights[i+1][j+1]*vertScale, pos.z+(j+1)*horScale);
		}
    }
    glEnd();
}

//Get the height at a certain point
float Terrain::getHeight(int x, int z) {
    if(x >= heights.size() || z >= heights[0].size()) {
        cout << "ERROR: Tried to access point outside terrain" << endl;
        return 0.0;
    }
    return pos.y + vertScale * heights[x][z];
}

//Get the normal at a certain point
glm::vec3 Terrain::getNormal(int x, int z) {
    if(x >= heights.size() || z >= heights[0].size()) {
        cout << "ERROR: Tried to access point outside terrain" << endl;
        return glm::vec3(0,0,0);
    }
    return normals[x][z];
}

//Get the length
int Terrain::getLength() {
    return (int) heights.size();
}

//Get the width
int Terrain::getWidth() {
    return (int) heights[0].size();
}

//Set the scale
void Terrain::setHorScale(float newScale) {
    horScale = newScale;
}

//Set the scale
void Terrain::setVertScale(float newScale) {
    vertScale = newScale;
}

//Set the position
void Terrain::setPos(glm::vec3 newPos) {
    pos = newPos;
}
