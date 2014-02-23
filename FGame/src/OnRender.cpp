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

#define GLM_FORCE_RADIANS
#include "glm/gtx/vector_angle.hpp"

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
    
    /** draw terrain **
    // draw terrain
    glBegin(GL_QUADS);
    // loop over vertices for each quad
    for (int x = 0; x < terrain.getRows() - 1; x++) {
        for (int z = 0; z < terrain.getCols() - 1; z++) {
            
            // light source vector
            glm::vec3 lightSrc(0.267261, 0.534522, 0.801784);
            // normal of quad associated with the bottom left point
            glm::vec3 normal = terrain.getNormal(x, z);
            // determine light scaling factor
            double scale = glm::angle(normal, lightSrc);
            

            // calculate RGB for bottom left point
            double red = scale;
            double green = scale;
            double blue = scale;
            glColor3f(0, green, blue);

            // add bottom left point to quad
            glVertex3d(x, terrain.getHeight(x, z), -z);
            
            // recalculate scale for the bottom right point
            normal = terrain.getNormal(x + 1, z);
            scale = glm::angle(normal, lightSrc);
            
            // calculate RGB for bottom right point
            red = scale;
            green = scale;
            blue = scale;
            glColor3f(0, green, blue);
            
            // add bottom right point to quad
            glVertex3d(x + 1, terrain.getHeight(x + 1, z), -z);
            
            // recalculate scale for top right point
            normal = terrain.getNormal(x + 1, z + 1);
            scale = glm::angle(normal, lightSrc);
            
            // calculate RGB for top right point
            red = scale;
            green = scale;
            blue = scale;
            glColor3f(0, green, blue);
            
            // add top right point to quad
            glVertex3d(x + 1, terrain.getHeight(x + 1, z + 1), -(z + 1));
            
            // recalculate scale for top left point
            normal = terrain.getNormal(x, z + 1);
            scale = glm::angle(normal, lightSrc);
            
            // calculate RGB for top left point
            red = scale;
            green = scale;
            blue = scale;
            glColor3f(0, green, blue);
            
            // add top left point to quad
            glVertex3d(x, terrain.getHeight(x, z + 1), -(z + 1));
        }
    }
    glEnd();
*/
    /** Clear color and depth buffer. **/
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    collectables.drawElements();
    
    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glOrtho(0, 640, 480, 0, -1, 1);
    theHUD.drawElements();
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();

    /** Swap buffers. **/
    SDL_GL_SwapWindow(window);
}
