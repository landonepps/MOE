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
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#elif __APPLE__
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <SDL2/SDL.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#endif

#include "Events.h"
#include "Clock.h"
#include "Image.h"
#include "HUD.h"
#include "Counter.h"
#include "Gauge.h"
#include "Music.h"
#include "Mesh.h"
#include "Constants.h"
#include "Object.h"
#include "Treasure.h"
#include "Camera.h"
#include <string>

class FGame : public Events
{

    private:
        /** While true, the game should be running. When set to false the game
         *  will exit gracefully. **/
        bool running;

        /** Used to represent main game loop time. **/
        Clock mainClock;

        /** The main window/screen the user sees. **/
        SDL_Window   *window;
        SDL_Renderer *renderer;
        SDL_GLContext context;
    
        /** Background music. **/
        Music bgm;

        /** Test mesh. **/
        Mesh *testMesh;
        Image testTex;

        /** The HUD objects**/
        HUD theHUD;
        Counter timer;
        Gauge hBar;
    
#warning remove later
        /** The Camera **/
        Camera *cam;

        /** The game objects **/
        Object collectables;
        Treasure treasure1;

        /** Resolution of the main window. **/
        int width;
        int height;

        SDL_Joystick *joystick1;

    public:

        /** Will store the path of the executable. **/
        string path;

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
         * OnInit:    Initializes Counter, audio, video, cdrom, and joystick.
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
         * OnJoyButtonDown: Currently does nothing.
         *
         * which:     The index of the joystick that reported the event.
         *
         * button:    The index of the button that changed.
         *
         * returns:   void.
        ***********************************************************************/
        void OnJoyButtonDown(Uint8 which, Uint8 button);
    
        /***********************************************************************
         * OnJoyButtonUp: Currently does nothing.
         *
         * which:     The index of the joystick that reported the event.
         *
         * button:    The index of the button that changed.
         *
         * returns:   void.
        ***********************************************************************/
        void OnJoyButtonUp(Uint8 which, Uint8 button);

        /***********************************************************************
         * OnKeyDown: Handle keyboard key down
         *
         * sym:       The SDL virtual key representation.
         *
         * mod:       The SDL physical key representation.
         *
         * scancode:  Current key modifiers.
         *
         * returns:   void.
        ***********************************************************************/
        void OnKeyDown(SDL_Keycode sym, Uint16 mod,
                               SDL_Scancode scancode);

        /***********************************************************************
         * OnKeyUp:   Handle keyboard key up
         *
         * sym:       The SDL virtual key representation.
         *
         * mod:       The SDL physical key representation.
         *
         * scancode:  Current key modifiers.
         *
         * returns:   void.
        ***********************************************************************/
        void OnKeyUp(SDL_Keycode sym, Uint16 mod,
                             SDL_Scancode scancode);

        /***********************************************************************
         * OnLButtonDown: Speed up time.
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        void OnLButtonDown(int x, int y);

        /***********************************************************************
         * OnRButtonDown: Slow down time.
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        void OnRButtonDown(int x, int y);

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
