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

#ifndef CLOCK_H_
#define CLOCK_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class Clock
{
private:
    /** How many cycles have occurred. **/
    Uint64 timeCycles;
    
    /** How much to scale timeCycles by. **/
    float timeScale;
    
    /** Whether or not the game is paused. **/
    bool isPaused;
    
    /** Computer's cycles per seconds. **/
    static float cyclesPerSecond;
    
    /***********************************************************************
     * secondsToCycles: Converts seconds to cycles.
     *
     * timeSeconds: The time in seconds.
     *
     * returns:   The time in cycles.
     ***********************************************************************/
    static Uint64 secondsToCycles(float timeSeconds);
    
    /***********************************************************************
     * cyclesToSeconds: Converts cycles to seconds. WARNING: only use to
     *            convert small durations into seconds.
     *
     * timeSeconds: The time in cycles.
     *
     * returns:   The time in seconds.
     ***********************************************************************/
    static float cyclesToSeconds(Uint64 timeCycles);
    
    /***********************************************************************
     * Clock:     Sets timeCycles based on start time. Also, sets timeScale
     *            to one and isPaused to false.
     *
     * startTimeSeconds: What the starting time is.
     ***********************************************************************/
    explicit Clock(float startTimeSeconds = 0);
    
public:
    
    static Clock* getInstance() {
        static Clock instance;
        
        return &instance;
    }
    
    /***********************************************************************
     * init:      Sets the clock's cyclesPerSecond. Call when game
     *            first starts.
     *
     * returns:   void.
     ***********************************************************************/
    static void init();
    
    
    /***********************************************************************
     * getTimeCycles: Return the current time in cycles.
     *
     * returns:   Return the current time in cycles.
     ***********************************************************************/
    Uint64 getTimeCycles() const;
    
    /***********************************************************************
     * calcDeltaSeconds: Determine the difference between this clock's
     *            absolute time and that of another clock.
     *
     * other:     The clock who's time we will compare.
     *
     * returns:   The clock difference in seconds.
     ***********************************************************************/
    float calcDeltaSeconds(const Clock &other);
    
    /***********************************************************************
     * update:    Updates timeCycles based on the realTime in seconds. This
     *            function should be called once per frame, with the real
     *            measured frame time delta in seconds.
     *
     * dtRealSeconds: The real measured frame time delta (in seconds).
     *
     * returns:   void.
     ***********************************************************************/
    void update(float dtRealSeconds);
    
    /***********************************************************************
     * setPaused: Pauses/unpauses the clock.
     *
     * isPaused:  Whether or not the clock should be paused.
     *
     * returns:   void.
     ***********************************************************************/
    void setPaused(bool isPaused);
    
    /***********************************************************************
     * getPaused: Returns true if the clock is paused, returns false
     *            otherwise.
     *
     * returns:   True if the clock is paused, returns false otherwise.
     ***********************************************************************/
    bool getIsPaused() const;
    
    /***********************************************************************
     * setTimeScale: Set the scale of the clock timeCycle.
     *
     * scale:     How much to scale the clock timeCycle (default 1).
     *
     * returns:   void.
     ***********************************************************************/
    void setTimeScale(float scale);
    
    /***********************************************************************
     * getTimeScale: Returns the scale of the clock timeCycle.
     *
     * returns:   The scale of the clock timeCycle.
     ***********************************************************************/
    float getTimeScale() const;
    
    /***********************************************************************
     * singleStep: Updates timeCycles while game is paused.
     *
     * returns:   void.
     ***********************************************************************/
    void singleStep();
    
    /***********************************************************************
     * getElapsedTime: Returns the elapsed time (affected by timeScale).
     *
     * returns:   Elapsed time.
     ***********************************************************************/
    float getElapsedTime();
};

#endif /* CLOCK_H_ */
