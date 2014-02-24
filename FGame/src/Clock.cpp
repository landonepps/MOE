/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/06/2014
 *
 * Clock used to represent game time.
 ******************************************************************************/

#include "Clock.h"

/** Define static variable. **/
float Clock::cyclesPerSecond = 0;

/***********************************************************************
 * secondsToCycles: Converts seconds to cycles.
 *
 * timeSeconds: The time in seconds.
 *
 * returns:   The time in cycles.
 ***********************************************************************/
Uint64 Clock::secondsToCycles(float timeSeconds)
{
    return (Uint64) (timeSeconds * cyclesPerSecond);
}

/***********************************************************************
 * cyclesToSeconds: Converts cycles to seconds. WARNING: only use to
 *            convert small durations into seconds.
 *
 * timeSeconds: The time in cycles.
 *
 * returns:   The time in seconds.
 ***********************************************************************/
float Clock::cyclesToSeconds(Uint64 timeCycles)
{
    return (float)timeCycles / cyclesPerSecond;
}

/***********************************************************************
 * init:      Sets the clock's cyclesPerSecond. Call when game
 *            first starts.
 *
 * returns:   void.
 ***********************************************************************/
void Clock::init()
{
    cyclesPerSecond = (float)SDL_GetPerformanceFrequency();
}

/***********************************************************************
 * Clock:     Sets timeCycles based on start time. Also, sets timeScale
 *            to one and isPaused to false.
 *
 * startTimeSeconds: What the starting time is.
 ***********************************************************************/
Clock::Clock(float startTimeSeconds)
{
    timeCycles = secondsToCycles(startTimeSeconds);
    timeScale  = 1;
    isPaused   = false;
}

/***********************************************************************
 * getTimeCycles: Return the current time in cycles.
 *
 * returns:   Return the current time in cycles.
 ***********************************************************************/
Uint64 Clock::getTimeCycles() const
{
    return timeCycles;
}

/***********************************************************************
 * calcDeltaSeconds: Determine the difference between this clock's
 *            absolute time and that of another clock.
 *
 * other:     The clock who's time we will compare.
 *
 * returns:   The clock difference in seconds.
 ***********************************************************************/
float Clock::calcDeltaSeconds(const Clock &other)
{
    Uint64 dt = timeCycles - other.timeCycles;
    return cyclesToSeconds(dt);
}

/***********************************************************************
 * update:    Updates timeCycles based on the realTime in seconds. This
 *            function should be called once per frame, with the real
 *            measured frame time delta in seconds.
 *
 * dtRealSeconds: The real measured frame time delta (in seconds).
 *
 * returns:   void.
 ***********************************************************************/
void Clock::update(float dtRealSeconds)
{
    if(isPaused == false)
    {
        Uint64 dtScaledCycles = secondsToCycles(dtRealSeconds * timeScale);
        timeCycles += dtScaledCycles;
    }
}

/***********************************************************************
 * setPaused: Pauses/unpauses the clock.
 *
 * isPaused:  Whether or not the clock should be paused.
 *
 * returns:   void.
 ***********************************************************************/
void Clock::setPaused(bool isPaused)
{
    this->isPaused = isPaused;
}

/***********************************************************************
 * getPaused: Returns true if the clock is paused, returns false
 *            otherwise.
 *
 * returns:   True if the clock is paused, returns false otherwise.
 ***********************************************************************/
bool Clock::getIsPaused() const
{
    return isPaused;
}

/***********************************************************************
 * setTimeScale: Set the scale of the clock timeCycle.
 *
 * scale:     How much to scale the clock timeCycle (default 1).
 *
 * returns:   void.
 ***********************************************************************/
void Clock::setTimeScale(float scale)
{
    timeScale = scale;
}

/***********************************************************************
 * getTimeScale: Returns the scale of the clock timeCycle.
 *
 * returns:   The scale of the clock timeCycle.
 ***********************************************************************/
float Clock::getTimeScale() const
{
    return timeScale;
}

/***********************************************************************
 * singleStep: Updates timeCycles while game is paused.
 *
 * returns:   void.
 ***********************************************************************/
void Clock::singleStep()
{
    if(isPaused == true)
    {
        /** 1 / 30 represents seconds / frames. **/
        Uint64 dtScaledCycles = secondsToCycles((1.0f / 30.0f) * timeScale);
        timeCycles += dtScaledCycles;
    }
}

/***********************************************************************
 * getElapsedTime: Returns the elapsed time (affected by timeScale).
 *
 * returns:   Elapsed time.
 ***********************************************************************/
float Clock::getElapsedTime()
{
    return timeCycles / cyclesPerSecond;
}
