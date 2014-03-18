/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Handles basic calculations (such as animation). Currently does nothing.
*******************************************************************************/

#include "FGame.h"      /** Contains prototype for OnLoop. **/
#include <cstdlib>

/***********************************************************************
 * OnLoop:    Handles basic calculations (such as animation). Currently
 *            does nothing.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnLoop()
{
    timer.setValue(90 - mainClock->getElapsedTime());
    if (frames >= 100){
        float FPS = frames / (mainClock->getElapsedTime() - lastFrame) * mainClock->getTimeScale();
        fpsCount.setValue((float)FPS);
        frames = 0;
        lastFrame = mainClock->getElapsedTime();
    }
    player.update();

    if ((int)mainClock->getElapsedTime() == 2 && currentLevel < 4){
        win.setValue(" ");
    }

    if ((treasures.size() == 0 || mainClock->getElapsedTime() >= 90) && currentLevel < 4){
        mainClock->reset();

        if ((float)enemy.getStatData(0)->second > (float)player.getStatData(0)->second)
            win.setValue("Poor Wins");
        else if ((float)enemy.getStatData(0)->second < (float)player.getStatData(0)->second)
            win.setValue("You Wins");
        else 
            win.setValue("Nobody Wins");

        currentLevel++;
        if (currentLevel == 4){
            win.setValue("Game Over Wins");
        }
        else{
            enemy.setDifficulty(currentLevel);

            furnitureSelected = false;

            treasures.clear();

            player.setPos(glm::vec3(0,-25,0));

            /** Add a player stat for furniture count**/
            player.getStatData(0)->second = 0;

            enemy.getStatData(0)->second = 0;

            /** Load music, room, pickups and decorations,**/
        #ifdef _WIN32
                    glm::vec3 randomRange;
                    float envx = (Skybox::getInstance()->getDimensions().x / 2) - 50;
                    float envy = Skybox::getInstance()->getDimensions().y - 50;
                    float envz = (Skybox::getInstance()->getDimensions().z / 2) - 50;

                    randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                    randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                    randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                    //enemy.setLocation(randomRange.x, randomRange.y, randomRange.z);
                    enemy.setLocation(0, -25, 0);

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup(".\\assets\\poltroncina.ply", ".\\assets\\poltroncina.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setBob(true, 5, 6, 6);
                        temp.setRotate(true, false, 25);
                        treasures.push_back(temp);
                    }

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup(".\\assets\\tavolo1.ply", ".\\assets\\tavolo1.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setRotate(true, true, 25);
                        treasures.push_back(temp);
                    }

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup(".\\assets\\letto.ply", ".\\assets\\letto.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setBob(true, 10, 5, 5);
                        treasures.push_back(temp);
                    }

        #else

                    glm::vec3 randomRange;
                    float envx = (Skybox::getInstance()->getDimensions().x / 2) - 50;
                    float envy = Skybox::getInstance()->getDimensions().y - 50;
                    float envz = (Skybox::getInstance()->getDimensions().z / 2) - 50;

                    randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                    randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                    randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                    enemy.setLocation(randomRange.x, randomRange.y, randomRange.z);

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup("./assets/poltroncina.ply", "./assets/poltroncina.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setBob(true, 5, 6, 6);
                        temp.setRotate(true, false, 25);
                        treasures.push_back(temp);
                    }

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup("./assets/tavolo1.ply", "./assets/tavolo1.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setRotate(true, true, 25);
                        treasures.push_back(temp);
                    }

                    for (int i = 0; i < 5; i++){
                        randomRange.x = ((float(rand()) / float(RAND_MAX)) * (envx - (-envx)) + (-envx));
                        randomRange.y = ((float(rand()) / float(RAND_MAX)) * (envx - (50)) + (50));
                        randomRange.z = ((float(rand()) / float(RAND_MAX)) * (envx - (-envz)) + (-envz));
                        Treasure temp;
                        temp.setup("./assets/letto.ply", "./assets/letto.png");
                        temp.setScale(25, 25, 25);
                        temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                        temp.setBob(true, 10, 5, 5);
                        treasures.push_back(temp);
                    }

        #endif

            furnitureCount.setValue(0);
            enemyFurnitureCount.setValue(0);
            timer.setValue(90);

            /**Add all the furniture to the collections**/
            for (int i = 0; i < treasures.size(); i++){
                collectables.addPropElement(&treasures[i]);
            }

            totalTreasures = treasures.size();
        }  
    }
}
