/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:      7-Feb-2014
 *
 * Counter class
*******************************************************************************/

#include "Counter.h"
#include <iostream>
#include <iomanip>

#define GL_CLAMP_TO_EDGE 0x812F

#ifndef GL_BGR_EXT
#define GL_BGR_EXT 0x80E0
#endif

#ifndef GL_BGRA_EXT
#define GL_BGRA_EXT 0x80E1
#endif

Counter::Counter() : HUDelement()
{
    xPosition = 0;
    yPosition = 0;
    value   = 0.0f;
    precision = 0;
    font      = NULL;
}

Counter::Counter(int id) : HUDelement(id)
{
    xPosition = 0;
    yPosition = 0;
    value   = 0.0f;
    precision = 0;
    font      = NULL;
}

/***********************************************************************
* setup:   Sets up the Counter HUD type using developer specified variables
*
* fontfile: the name of the .ttf file
* R: red value
* G: green value
* B: blue value
* xPos: x coordinate of where to place the Counter
* yPos: y coordinate of where to place the Counter
* fontSize: size of the font
* precision: precision of Counter desired by user.
* id: an id for this HUD type if desired.
*
* returns:   void.
***********************************************************************/
void Counter::setup(const string &fontFile, const GLubyte& R, const GLubyte& G, const GLubyte& B,
    const double& xPos, const double& yPos, int fontSize, int precision, int id)
{
    this->precision = precision;
    xPosition = xPos;
    yPosition = yPos;
    this->fontFile = fontFile;
    this->fontSize = fontSize;
    color.r = R;
    color.g = G;
    color.b = B;
}

Counter::~Counter(){

}
/***********************************************************************
* setValue:   Sets the value to be displayed
*
* val:  the value remaining
*
* returns:   void.
***********************************************************************/
void Counter::setValue(float val){
    value = val;
}

/***********************************************************************
 * draw:   Simply draws the Counter to the screen
 *
 * returns:   void.
***********************************************************************/
void Counter::draw(){

    stringstream message;
    message << fixed << setprecision(precision) << value;
    
    // Open the font
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL) {
        string error = TTF_GetError();
        cerr << "failed to load font: " << fontFile << " " << TTF_GetError() << endl;
    }

    // Create the surface to copy to the renderer
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.str().c_str(), color);
    if (surf == NULL){
		TTF_CloseFont(font);
		return;
	}

    GLuint Texture = 0;

    // Create the texture
    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);

    // Enable texture parameters
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    // Render the text to 2D by referencing its pixel data
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_BGRA_EXT,
                    GL_UNSIGNED_BYTE, surf->pixels);

    // Enable 2D Texture and alpha blend
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Draw the text
    glBegin(GL_QUADS);
        glTexCoord2d(0, 1); glVertex3d(xPosition, yPosition + surf->h, 0);
        glTexCoord2d(1, 1); glVertex3d(xPosition + surf->w, yPosition + surf->h, 0);
        glTexCoord2d(1, 0); glVertex3d(xPosition + surf->w, yPosition, 0);
        glTexCoord2d(0, 0); glVertex3d(xPosition, yPosition, 0);        
    glEnd();

    // Clean up
    SDL_FreeSurface(surf);
    TTF_CloseFont(font);
    glDisable(GL_BLEND);
    glDisable(GL_TEXTURE_2D); 
    glDeleteTextures(1, &Texture);
}
