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

#ifndef FGAME_H_
#define FGAME_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif
#include "Events.h"
#include "Clock.h"
#include "Image.h"
#include "Timer.h"
#include "Healthbar.h"
#include "Animation.h"
#include "Music.h"
#include "Player.h"
#include "Constants.h"
#include "HUD.h"

class FGame : public Events
{

    private:
        /** While true, the game should be running. When set to false the game
         *  will exit gracefully. **/
        bool running;

        /** Used to represent main game loop time. **/
        Clock mainClock;

        /** The main window/screen the user sees. **/
        SDL_Window *screen;
        SDL_Renderer *renderer;
    
        // TODO: Remove later
        // test elements
        Image character;
        Image foreground;
        Image background;
    
        Music bgm;
    
        HUD theHUD;
        Healthbar hp;
        Timer timer;

        Animation poorAnim;
        Image poorImg;
        Image poorImg2;
    
        bool punch1;
        bool punch2;

		Player p1;
		Player p2;


        /** Resolution of the main window. **/
        int width;
        int height;

        float roundLength;

        SDL_Joystick *joystick1;

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
         * OnJoyButtonDown: Close application if a joystick button is pressed
         *                  (test).
         *
         * which:     The index of the joystick that reported the event.
         *
         * button:    The index of the button that changed.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

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
