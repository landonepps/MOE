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
    
    if (!mainClock.getIsPaused()){
        timer.setTime(timeRemaining);
        
        /** Bad code, want to change later. **/
        if(punch1){
            p1.punch(&mainClock);
            punch1 = false;
        }
        else {
            p1.walk(&mainClock);
        }
        if(punch2){
            p2.punch(&mainClock);
            punch2 = false;
        }
        else {
            p2.walk(&mainClock);
        }
        
        p1.checkCollision(&p2);
        p2.checkCollision(&p1);
    }
    if(timeRemaining <= 0.0){
        timer.setTime(0);
        p1.halt();
        p2.halt();
        bgm.stop();
        mainClock.setPaused(true);
    }
}
