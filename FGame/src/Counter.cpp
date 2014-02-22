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
* cl: font color 
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
    font = TTF_OpenFont(fontFile.c_str(), fontSize);
    if (font == NULL) {
		string error = TTF_GetError();
        cerr << "failed to load font: " << fontFile << " " << TTF_GetError() << endl;
    }
    color.r = R;
    color.g = G;
    color.b = B;
}

Counter::~Counter(){
   // TTF_CloseFont(font);
}
/***********************************************************************
* setTime:   Sets the time remaining to be displayed
*
* timeLeft:  the time remaining in the round
*
* returns:   void.
***********************************************************************/
void Counter::setValue(float val){
    value = val;
}

/***********************************************************************
 * draw:   Simply draws the Counter to the screen
 *
 * renderer: The SDL renderer to be rendered to.
 *
 * returns:   void.
***********************************************************************/
void Counter::draw(){

    stringstream message;
    message << fixed << setprecision(precision) << value;
    
    // Create the surface to copy to the renderer
    SDL_Surface *surf = TTF_RenderText_Blended(font, message.str().c_str(), color);
    if (surf == NULL){
		TTF_CloseFont(font);
		return;
	}

    unsigned Texture = 0;

    glGenTextures(1, &Texture);
    glBindTexture(GL_TEXTURE_2D, Texture);

    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, surf->w, surf->h, 0, GL_RGBA,
                    GL_UNSIGNED_BYTE, surf->pixels);

    glBegin(GL_QUADS);
        glTexCoord2d(0, 0); glVertex3d(xPosition, yPosition, 1);
        glTexCoord2d(1, 0); glVertex3d(xPosition + surf->w, yPosition, 1);
        glTexCoord2d(1, 1); glVertex3d(xPosition + surf->w, yPosition + surf->h, 1);
        glTexCoord2d(0, 1); glVertex3d(xPosition, yPosition + surf->h, 1);
    glEnd();

    glDeleteTextures(1, &Texture);
    // Cleans up the surface and texture
    SDL_FreeSurface(surf);
}
