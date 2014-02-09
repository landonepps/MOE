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
<<<<<<< HEAD
    float timeRemaining = roundLength - mainClock.getElapsedTime();
    if (!mainClock.getIsPaused()){
        timer.setTime(timeRemaining);
    }
    if(timeRemaining <= 0.0){
        timer.setTime(0);
        mainClock.setPaused(true);
=======
    
    if (!mainClock.getIsPaused()) {
        timer.setTime(mainClock.getElapsedTime());
        poorAnim.OnAnimate(&mainClock);
>>>>>>> 07ebb537441967b034619a39934b493c8c08b5c1
    }
}
