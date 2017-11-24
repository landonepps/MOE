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
#include "Prop.h"
#include "Treasure.h"
#include "Camera.h"
#include "Player.h"
#include "Enemy.h"
#include "Skybox.h"
#include "Message.h"
#include "Terrain.h"

#include <string>

class FGame : public Events
{
    
private:
    /** While true, the game should be running. When set to false the game
     *  will exit gracefully. **/
    bool running;

    int frames;

    int currentLevel;

    int totalTreasures;

    float lastFrame;

    int poorScore;

    int playerScore;

    bool furnitureSelected;
    /** Used to represent main game loop time. **/
    Clock *mainClock;
    
    /** The main window/screen the user sees. **/
    SDL_Window   *window;
    SDL_Renderer *renderer;
    SDL_GLContext context;
    
    /** Background music. **/
    Music bgm;
    
    /** The HUD Props**/
    HUD theHUD;
    Counter fpsCount;
    Counter furnitureCount;
    Counter enemyFurnitureCount;
    Message win;
    Gauge timer;
    
    /** The Camera **/
    Player player;
    
    Enemy *enemy;

    /** The landscape **/
    Skybox *sky;
    
    /** The terrain **/
    Terrain *terrain;
    
    /** The game Props **/
    Prop collectables;
    vector<Treasure> treasures;

    /** Pick-up sound **/
    SFX pickUp;

    /** Bool for turning on hitboxes **/
    bool hitbox;
    
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
    
    ~FGame() {
        /** Free any used resources and exit. **/
        OnCleanup();
    }
    
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
     * OnJoyAxis: Called when the joystick axis is moved. Controls player
     *            movement and rotation.
     *
     * which:     The index of the joystick that reported the event.
     *
     * axis:      The index of the axis that changed.
     *
     * value:     The current position of the axis (range: -32768 to 32767).
     *
     * returns:   void.
     ***********************************************************************/
    void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

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
