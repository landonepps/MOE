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
        int  lastFrame;
        bool oscillates;

        /***********************************************************************
         * Animation: Constructor (Default: frameInc = 1, oscillates = false).
        ***********************************************************************/
        Animation();

        /***********************************************************************
         * OnAnimate: Updates animation frame according to compute speed.
         *
         * clock:     Clock that handles games time.
         *
         * returns:   void.
        ***********************************************************************/
        void OnAnimate(Clock *clock);

        /***********************************************************************
         * setFrameRate: Sets the animation's frame rate.
         *
         * rate:      The frame rate in milliseconds.
         *
         * returns:   void.
        ***********************************************************************/
        void setFrameRate(int rate);

        /***********************************************************************
         * setCurrentFrame: Sets the animation's current frame.
         *
         * frame:     A frame in the image's animation.
         *
         * returns:   void.
        ***********************************************************************/
        void setCurrentFrame(int frame);

        /***********************************************************************
         * getCurrentFrame: Returns the animation's current frame.
         *
         * returns:   The animation's current frame.
        ***********************************************************************/
        int getCurrentFrame();
};

#endif /* ANIMATION_H_ */
