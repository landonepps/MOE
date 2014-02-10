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

#include "Animation.h"
#include <iostream>
using namespace std;
Animation::Animation()
{
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;

    /** Milliseconds. **/
    frameRate = 100;
    oldTime = 0;

    oscillates = false;
}

void Animation::OnAnimate(Clock *clock)
{
    if(oldTime + frameRate > (clock->getElapsedTime() * 1000))
    {
        return;
    }

    oldTime = (clock->getElapsedTime() * 1000);
    currentFrame += frameInc;

    if(oscillates == true)
    {
        if(frameInc > 0)
        {
            if(currentFrame >= maxFrames)
            {
                frameInc = -maxFrames;
            }
            else
            {
                if(currentFrame <= 0)
                {
                    frameInc = -frameInc;
                }
            }
        }
    }
    else
    {
        if(currentFrame >= maxFrames)
        {
            currentFrame = 0;
        }
    }
}

void Animation::setFrameRate(int rate)
{
    frameRate = rate;
}

void Animation::setCurrentFrame(int frame)
{
    if(frame < 0 || frame >= maxFrames)
    {
        return;
    }

    currentFrame = frame;
}

int Animation::getCurrentFrame()
{
    return currentFrame;
}
