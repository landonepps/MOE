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
    sky->setPos(player.getPos());
    
    static unsigned int index = -1;
    
    if (!furnitureSelected && treasures.size() > 0){
        index = (int)((float(rand()) / float(RAND_MAX)) * treasures.size() - 1);
        furnitureSelected = true;
    }
    
    if (treasures.size() > 0){
        enemy->runAI(treasures[index].getPosition());
    }

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
            break;
        }
        if (enemy->checkCollision(treasures[i].getPosition(), treasures[i].getDimensions())){
            pickUp.play();
            enemy->getStatData(0)->second += 1;
            enemyFurnitureCount.setValue((float)enemy->getStatData(0)->second);
            treasures.erase(treasures.begin() + i);
            collectables.removePropElement();
            collision = true;
            furnitureSelected = false;
            break;
        }
    }

    if ((int)mainClock->getElapsedTime() > 3 && currentLevel < 4){
        win.setValue(" ");
    }
    
    if ((treasures.size() == 0 || mainClock->getElapsedTime() >= 90) && currentLevel < 4){
        mainClock->reset();

        if ((float)enemy->getStatData(0)->second >(float)player.getStatData(0)->second){
            win.setValue("Poor Wins");
            poorScore++;
        }
        else if ((float)enemy->getStatData(0)->second < (float)player.getStatData(0)->second){
            win.setValue("You Wins");
            playerScore++;
        }
        else
            win.setValue("Nobody Wins");
        
        currentLevel++;
        if (currentLevel == 4){
            win.setValue("Game Over Wins");
            furnitureCount.setValue(playerScore);
            enemyFurnitureCount.setValue(poorScore);
            mainClock->setPaused(true);
        }
        else{
            delete enemy;

            enemy = new Enemy();

            enemy->setDifficulty(currentLevel);
            
            furnitureSelected = false;
            index = -1;
            
            treasures.clear();
            collectables.clear();

            player.setPos(glm::vec3(0,-25,0));
            
            /** Add a player stat for furniture count**/
            player.getStatData(0)->second = 0;
            
            enemy->addStat(1,0);
            enemy->setVel(glm::vec3());
            
            /** Load music, room, pickups and decorations,**/
#ifdef _WIN32

            int horScale = 100;
            terrain->setHorScale(horScale);
            terrain->setPos(glm::vec3(0, 0, 0));
            int vertScale = 500;
            terrain->setVertScale(vertScale);
            int playerStartX = terrain->getWidth() / -2.0;
            int playerStartZ = terrain->getLength() / -2.0;
            player.setPos(glm::vec3(playerStartX, -terrain->getHeight(-playerStartX, -playerStartZ) - PLAYER_HEIGHT, playerStartZ));
            sky->setPos(player.getPos());
            
            glm::vec3 randomRange;
            float envx = terrain->getLength();
            float envz = terrain->getWidth();
            
            randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
            randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
            randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                             (250) + 500);
            enemy->setup(".\\assets\\puff.ply", ".\\assets\\poorpuff.png");
            enemy->setScale(25, 25, 25);
            enemy->setLocation(randomRange.x, randomRange.y, randomRange.z);
            
            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
                Treasure temp;
                temp.setup(".\\assets\\poltroncina.ply", ".\\assets\\poltroncina.png");
                temp.setScale(25, 25, 25);
                temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                temp.setBob(true, 5, 6, 6);
                temp.setRotate(true, false, 25);
                treasures.push_back(temp);
            }
            
            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
                Treasure temp;
                temp.setup(".\\assets\\tavolo1.ply", ".\\assets\\tavolo1.png");
                temp.setScale(25, 25, 25);
                temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                temp.setRotate(true, true, 25);
                treasures.push_back(temp);
            }
            
            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
                Treasure temp;
                temp.setup(".\\assets\\letto.ply", ".\\assets\\letto.png");
                temp.setScale(25, 25, 25);
                temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                temp.setBob(true, 10, 5, 5);
                treasures.push_back(temp);
            }
            
#else
            int horScale = 100;
            terrain->setHorScale(horScale);
            terrain->setPos(glm::vec3(0, 0, 0));
            int vertScale = 500;
            terrain->setVertScale(vertScale);
            int playerStartX = terrain->getWidth() / -2.0;
            int playerStartZ = terrain->getLength() / -2.0;
            player.setPos(glm::vec3(playerStartX, -terrain->getHeight(-playerStartX, -playerStartZ) - PLAYER_HEIGHT, playerStartZ));
            sky->setPos(player.getPos());
            
            glm::vec3 randomRange;
            float envx = terrain->getLength();
            float envz = terrain->getWidth();
            
            randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
            randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
            randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                             (250) + 500);
            enemy->setup("./assets/puff.ply", "./assets/poorpuff.png");
            enemy->setScale(25, 25, 25);
            enemy->setLocation(randomRange.x, randomRange.y, randomRange.z);

            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
                Treasure temp;
                temp.setup("./assets/poltroncina.ply", "./assets/poltroncina.png");
                temp.setScale(25, 25, 25);
                temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                temp.setBob(true, 5, 6, 6);
                temp.setRotate(true, false, 25);
                treasures.push_back(temp);
            }
            
            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
                Treasure temp;
                temp.setup("./assets/tavolo1.ply", "./assets/tavolo1.png");
                temp.setScale(25, 25, 25);
                temp.setLocation(randomRange.x, randomRange.y, randomRange.z);
                temp.setRotate(true, true, 25);
                treasures.push_back(temp);
            }
            
            for (int i = 0; i < 5; i++){
                randomRange.x = ((float(rand()) / float(RAND_MAX)) * envx * 0.60) + envx * 0.30;
                randomRange.z = ((float(rand()) / float(RAND_MAX)) * envz * 0.60) + envz * 0.30;
                randomRange.y = ((float(rand()) / float(RAND_MAX)) *
                                 (250) + 500);
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
