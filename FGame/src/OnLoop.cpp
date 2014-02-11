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
    // SpeedControl::FPSCorrection.OnLoop();
    
    // p1.OnLoop(&mainClock);
    // p2.OnLoop(&mainClock);
    
    p1.update(&mainClock);
    
    if (!mainClock.getIsPaused()){
        timer.setTime(timeRemaining);
        
        /** Bad code, want to change later. **/
        if(punch1){
            p1.punch();
            punch1 = false;
            punchSFX.play();
        }
        else {
            // p1.aniControl.maxFrames = 5;
            // p1.OnAnimate(&mainClock);
        }
    }
    if(timeRemaining <= 0.0){
        timer.setTime(0);
        bgm.stop();
        mainClock.setPaused(true);
    }
}
