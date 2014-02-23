//
//  Terrain.cpp
//  MOE
//
//  Created by Landon Epps on 2/22/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Terrain.h"

#include <fstream>

using namespace std;

string getWord( istream &input ) {
    string word;
    
    char ch;
    input.get( ch );
    
    // Skip until we see the start of a word.
    while ( input && ( isspace( ch ) || ch == '#' ) ) {
        // If we see a comment, skip the rest of the line.
        if ( ch == '#' ) {
            input.get( ch );
            while ( input && ch != '\n' ) {
                input.get( ch );
            }
        }
        
        input.get( ch );
    }
    
    // Fold non-whitespace characters into the word.
    while ( input && !isspace( ch ) && ch != '#' ) {
        word += ch;
        
        input.get( ch );
    }
    
    return word;
}

Terrain::Terrain() {
    
}

Terrain::~Terrain() {

}

/** Unnecessary duplication of code. */
static glm::vec3 computeNormal( double h1, double h2, double h3, double h4 ) {
    glm::vec3 p1( 0, h1, 0 );
    glm::vec3 p2( 0, h2, 1 );
    glm::vec3 p3( 1, h3, 1 );
    glm::vec3 p4( 1, h4, 0 );
    
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
    
    return glm::normalize(n);
}

bool Terrain::loadTerrain(const char *filename) {
    ifstream input(filename, ios::binary);
    
    if (getWord(input) != "P5") {
        return false;
    }
    
    // Read the width and height
    string wstr = getWord( input );
    string hstr = getWord( input );
    cols = atoi( wstr.c_str() );
    rows = atoi( hstr.c_str() );
    
    // Make sure we got a meaningful width and height.
    if ( rows <= 0 || cols <= 0 )
        return false;
    
    // Read and sanity check the depth.
    if ( getWord( input ) != "255" )
        return false;
    
    // Allocate a height buffer for the image data
    height = new double [ rows * cols ];
    
    // Read image data and convert to floating point, [ 0 .. MAX_HEIGHT ]
    for ( int i = 0; i < rows * cols; i++ ) {
        char val;
        input.get( val );
        height[ i ] = ((unsigned char) val) * MAX_HEIGHT / 255.0;
    }
    
    // If we were not able to read everything, return failure.
    if ( !input )
        return false;
    
    normal = new glm::vec3[ rows * cols ];
    
    /** Compute average normals for the vertices. */
    for (int x = 0; x < rows - 1; x++) {
        for (int z = 0; z < cols - 1; z++) {
            double h1 = getHeight(x, z);
            double h2 = getHeight(x + 1, z);
            double h3 = getHeight(x + 1, z + 1);
            double h4 = getHeight(x, z + 1);
            
            normal[x * cols + z] = computeNormal(h1, h2, h3, h4);
        }
    }
    
    return true;
}

