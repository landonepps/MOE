/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/09/2014
 *
 * Handles FPS control.
*******************************************************************************/

#include "SpeedControl.h"
 
SpeedControl SpeedControl::FPSCorrection;
 
SpeedControl::SpeedControl() {
    lastSecond     = 0;
    loopTime    = 0;
 
    factor    = 0;
 
    FPS   = 0;
	frameCount      = 0;
}
 
void SpeedControl::OnLoop() {
    if((lastSecond + 1000) < SDL_GetTicks()) {
        lastSecond = SDL_GetTicks();
 
        FPS = frameCount;
 
        frameCount = 0;
    }
 
    factor = ((SDL_GetTicks() - loopTime) / 1000.0f) * 32.0f;
 
    loopTime = SDL_GetTicks();
 
    frameCount++;
}
 
int SpeedControl::getFPS() {
    return FPS;
}
 
float SpeedControl::getFactor() {
    return factor;
}
