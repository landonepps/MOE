/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Starts the game and contains main game loop.
*******************************************************************************/
// GIT TEST
#ifndef FGAME_H_
#define FGAME_H_

#include "SDL2/SDL.h"   /** Contains all necessary SDL functions (ver 2). **/
#include "Events.h"

// if Macintosh
#ifdef __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
// if Windows/Linux
// include equivalent header files
#include <GL/glut.h>
#endif

class FGame : public Events
{

    private:
        /** While true, the game should be running. When set to false the game
         *  will exit gracefully. **/
        bool running;

        /** The main window/screen the user sees. **/
        SDL_Window *screen;
        SDL_GLContext glContext;

        /** Resolution of the main window. **/
        int width;
        int height;

    public:

        /***********************************************************************
         * FGame:     Sets the game as running and defines the window size.
        ***********************************************************************/
        FGame();

        /***********************************************************************
         * OnExecute: Starts the game and contains main game loop.
         *
         * returns:   Zero on success and anything less than zero on failure.
        ***********************************************************************/
        int OnExecute();




        /***********************************************************************
         * OnInit:    Initializes timer, audio, video, cdrom, and joystick.
         *            Also, creates the main window centered and allows opengl.
         *
         * returns:   True on success and false on failure.
        ***********************************************************************/
        bool OnInit();

        /***********************************************************************
         * OnEvent:   Translates SDL events to functions.
         *
         * param1:    The event caused by user (ex. button press, mouse etc.).
         *
         * returns:   void.
        ***********************************************************************/
        void OnEvent(SDL_Event* event);

        /***********************************************************************
         * OnExit:    Sets the application's running status to false.
         *
         * returns:   void.
        ***********************************************************************/
        void OnExit();

        /***********************************************************************
         * OnLoop:    Handles basic calculations (such as animation). Currently
         *            does nothing.
         *
         * returns:   void.
        ***********************************************************************/
        void OnLoop();

        /***********************************************************************
         * OnRender:  Draws images to the screen.
         *
         * returns:   void.
        ***********************************************************************/
        void OnRender();

        /***********************************************************************
         * OnCleanup: Frees any used resources.
         *
         * returns:   void.
        ***********************************************************************/
        void OnCleanup();
};

#endif /* FGAME_H_ */
