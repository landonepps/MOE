/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/9/2014
 *
 * Controls the speed based on FPS
*******************************************************************************/
#ifndef SPEEDCONTROL_H_
#define SPEEDCONTROL_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

class SpeedControl {
    public:
        static SpeedControl FPSCorrection;
 
    private:
		/** Computer's cycles per seconds. **/
        int     lastSecond;
        int     loopTime;
 
        float   factor;
 
        int     FPS;
        int    frameCount;
 
    public:
		/***********************************************************************
         * SpeedControl: Sets the current speedControl values
        ***********************************************************************/
        SpeedControl();
 
		/***********************************************************************
         * OnLoop:    Handles basic calculations for FPS control.
         *
         * returns:   void.
        ***********************************************************************/
        void    OnLoop();
 
    public:
		/***********************************************************************
         * getFactor:  Returns the current FPS.
		 *
         * returns:   The current FPS as an integer
        ***********************************************************************/
        int     getFPS();
 
	    /***********************************************************************
         * getFactor:  Returns the current speed offset.
		 *
         * returns:   The current speed offset as a float
        ***********************************************************************/
        float   getFactor();
};

#endif /* FGAME_H_ */
