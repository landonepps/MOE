/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/09/2014
 *
 * Handles image animation.
*******************************************************************************/

#ifndef ANIMATION_H_
#define ANIMATION_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include "Clock.h"

class Animation
{
    private:
        Uint64 oldTime;
        int    currentFrame;
        int    frameInc;
        int    frameRate;

    public:
        int  firstFrame;
        int lastFrame;
        bool oscillates;

        Animation();
        void OnAnimate(Clock *clock);
        void setFrameRate(int rate);
        void setCurrentFrame(int frame);
        int getCurrentFrame();
};

#endif /* ANIMATION_H_ */
