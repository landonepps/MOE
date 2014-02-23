//
//  Terrain.h
//  MOE
//
//  Created by Landon Epps on 2/22/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Terrain__
#define __MOE__Terrain__

#include "glm/glm.hpp"

const double MAX_HEIGHT = 10;

class Terrain {
    int rows, cols;
    double *height;
    glm::vec3 *normal;
    
public:
    Terrain();
    ~Terrain();
    
    bool loadTerrain(const char *filename);
    
    int getRows() {
        return rows;
    }
    
    int getCols() {
        return cols;
    }
    
    /** Return the height associated with the given location. */
    double getHeight( int r, int c ) {
        return height[ r * cols + c ];
    }
    
    /** Return an averaged normal associated with the given vertex location. */
    glm::vec3 getNormal( int r, int c ) {
        return normal[ r * cols + c ];
    }
};

#endif /* defined(__MOE__Terrain__) */
