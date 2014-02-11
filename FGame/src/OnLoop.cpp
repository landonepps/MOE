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

/***********************************************************************
 * OnLoop:    Handles basic calculations (such as animation). Currently
 *            does nothing.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnLoop()
{
    /** Updating animations etc. go here. **/
    float timeRemaining = roundLength - mainClock.getElapsedTime();
    
    p2.update(&mainClock);
    p1.update(&mainClock);
    
    hp1.setHealth(p1.getHealth());
    hp2.setHealth(p2.getHealth());
    
    if (!mainClock.getIsPaused()){
        timer.setTime(timeRemaining);
        
        /** Bad code, want to change later. **/
        if(punch1){
            p1.punch();
            p1.checkPunch(&p2);
            punch1 = false;
        }
        else {
            p1.walk();
        }
        if(punch2){
            p2.punch();
            p2.checkPunch(&p1);
            punch2 = false;
        }
        else {
            p2.walk();
        }
        
        p1.checkPlayerCollision(&p2);
        p2.checkPlayerCollision(&p1);
        p1.checkWallCollision();
        p2.checkWallCollision();
    }
    if(timeRemaining <= 0.0 || (p1.getHealth() <= 0 || p2.getHealth() <= 0)){
        timer.setTime(0);
        p1.halt();
        p2.halt();
        bgm.stop();
        mainClock.setPaused(true);
    }
}
