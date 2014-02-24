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
    hBar.setValue(50);
    if (frames >= 100){
        int FPS = frames / (mainClock->getElapsedTime() - lastFrame) * mainClock->getTimeScale();
        timer.setValue((float)FPS);
        frames = 0;
        lastFrame = mainClock->getElapsedTime();
    }
    player.update();
}
