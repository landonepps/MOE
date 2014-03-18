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
}

//Renders the terrain
void Terrain::render(float widthScale,float heightScale) {
	for(int i=0;i<heights.size()-1;i++)
		for(int j=0;j<heights[0].size()-1;j++)
		{
            //Draw the triangle strip
			glBegin(GL_TRIANGLE_STRIP);
                glVertex3f(i*widthScale,heights[i][j]*heightScale,j*widthScale);
                glVertex3f((i+1)*widthScale,heights[i+1][j]*heightScale,j*widthScale);
                glVertex3f(i*widthScale,heights[i][j+1]*heightScale,(j+1)*widthScale);
                glVertex3f((i+1)*widthScale,heights[i+1][j+1]*heightScale,(j+1)*widthScale);
			glEnd();
		}
}
