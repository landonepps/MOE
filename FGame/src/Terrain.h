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

using namespace std;

class Terrain {
    // The height vector
    vector<vector<float> > heights;
    
public:
    Terrain();
    ~Terrain();
    
    // Loads the terrain at file
    void load (const char* file);
    
    // Renders the terrain
    void render (float widthScale, float heightScale);
};



#endif /* defined(__MOE__Terrain__) */
