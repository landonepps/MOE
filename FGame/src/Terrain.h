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


#ifndef __MOE__Terrain__
#define __MOE__Terrain__

#include <vector>
#include "glm/glm.hpp"

using namespace std;

class Terrain {
    // The height vector
    vector<vector<float> > heights;
    
    // The normals
    vector<vector<glm::vec3> > normals;
    
    //The starting draw position
    glm::vec3 pos;
    
    //The horizontal scale of the terrain
    float horScale;
    
    //The vertical scale of the terrain
    float vertScale;
    
public:
    
    //Make a default terrain
    Terrain();
    
    //Make a terrain at 0,0,0 with scales hs and vs
    Terrain(float hs, float vs);
    
    //Make a terrain at position p of scales hs and vs
    Terrain(glm::vec3 p, float hs, float vs);
    
    // Loads the terrain at file
    void load (const char* file);
    
    // Renders the terrain
    void render ();
    
    //Get the height at a certain point
    float getHeight(int x, int z);
    
    //Get the length
    int getLength();
    
    //Get the width
    int getWidth();
    
    //Set the scale
    void setHorScale(float newScale);
    
    //Set the scale
    void setVertScale(float newScale);
    
    //Set the position
    void setPos(glm::vec3 newPos);
};



#endif /* defined(__MOE__Terrain__) */
