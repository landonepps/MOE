/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Draws images to the screen.
*******************************************************************************/

#include "FGame.h"      /** Contains OnRender prototype. **/
#include <iostream>

/***********************************************************************
 * OnRender:  Draws images to the screen.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnRender()
{
    /** Draw image etc. **/
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    SDL_RenderClear(renderer);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    /** Load camera matrix **/
    cam->multMatrix();

    /** Clear color and depth buffer. **/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    /**Draw the test mesh **/
    glEnable( GL_TEXTURE_2D );
    glBindTexture(GL_TEXTURE_2D, testTex.openglTex);
    testMesh->draw();

    collectables.drawElements();
    glDisable( GL_TEXTURE_2D );
    
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    gluOrtho2D(0, 640, 480, 0);
    theHUD.drawElements();
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();

    /** Swap buffers. **/
    SDL_GL_SwapWindow(window);
}
