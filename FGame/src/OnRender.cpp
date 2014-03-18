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
#include <cstdlib>

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
    /** Clear color and depth buffer. **/
    glClearColor(1, 1, 1, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Update camera to player position
    player.updateCamera();

    // draw skybox
    sky->draw();
    
    // Only affect the terrain with lighting.
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    // draw terrain
    terrain.render();
    glDisable(GL_LIGHTING);
    glDisable(GL_LIGHT0);

    collectables.drawElements();

    static glm::vec3 randomPos;
    static unsigned int index;

    if (!furnitureSelected && treasures.size() > 0){
        index = (int)((float(rand()) / float(RAND_MAX)) * treasures.size()) - 1;

        randomPos = treasures[index].getPosition();
        furnitureSelected = true;
    }

    enemy.runAI(randomPos);
    enemy.draw();

    bool collision = false;
    for (unsigned int i = 0; i < treasures.size() && !collision; i++){
        treasures[i].setHitbox(hitbox);
        if (player.checkCollision(treasures[i].getPosition(), treasures[i].getDimensions())){
            pickUp.play();
            player.getStatData(0)->second += 1;
            furnitureCount.setValue((float)player.getStatData(0)->second);
            treasures.erase(treasures.begin() + i);
            collectables.removePropElement();
            collision = true;
            if (i == index)
                furnitureSelected = false;
        }
    }

    for (unsigned int i = 0; i < treasures.size() && !collision; i++){
        treasures[i].setHitbox(hitbox);
        if (enemy.checkCollision(treasures[i].getPosition(), treasures[i].getDimensions())){
            pickUp.play();
            enemy.getStatData(0)->second += 1;
            enemyFurnitureCount.setValue((float)enemy.getStatData(0)->second);
            treasures.erase(treasures.begin() + i);
            collectables.removePropElement();
            collision = true;
            furnitureSelected = false;
        }
    }

    glPushMatrix();
    glLoadIdentity();
    glDisable(GL_DEPTH_TEST);
    glOrtho(0, 640, 480, 0, -1, 1);
    theHUD.drawElements();
    glEnable(GL_DEPTH_TEST);
    glPopMatrix();

    /** Swap buffers. **/
    SDL_GL_SwapWindow(window);
    frames++;
}
