/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       1/30/2014
 *
 * Handles any events caused by user (only Quit at the moment).
*******************************************************************************/

#include "FGame.h"      /** Contains event prototypes.  **/
#include <iostream>
using namespace std;

/***********************************************************************
 * OnEvent:   Handles any events caused by user.
 *
 * event:     The event caused by user (ex. button press, mouse etc.).
 *
 * returns:   void.
***********************************************************************/
void FGame::OnEvent(SDL_Event* event)
{
    Events::OnEvent(event);
}

/***********************************************************************
 * OnExit:    Sets the application's running status to false.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnExit()
{
    running = false;
}

/***********************************************************************
 * OnJoyButtonDown: Currently does nothing.
 *
 * which:     The index of the joystick that reported the event.
 *
 * button:    The index of the button that changed.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnJoyButtonDown(Uint8 which, Uint8 button)
{
    /** Do Nothing **/
}

/***********************************************************************
 * OnJoyButtonUp: Currently does nothing.
 *
 * which:     The index of the joystick that reported the event.
 *
 * button:    The index of the button that changed.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnJoyButtonUp(Uint8 which, Uint8 button)
{
    /** Do Nothing **/
}

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
void FGame::OnKeyDown(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
{
    switch (sym) {
        case SDLK_DOWN:
            player.setVel(glm::vec3(0, 0, -1));
            break;
            
        case SDLK_UP:
            player.setVel(glm::vec3(0, 0, 1));
            break;
            
        case SDLK_RIGHT:
            player.setAVel(glm::vec3(0, 1, 0));
            break;
        
        case SDLK_LEFT:
            player.setAVel(glm::vec3(0, -1, 0));
            break;
            
        default:
            break;
    }
}

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
void FGame::OnKeyUp(SDL_Keycode sym, Uint16 mod, SDL_Scancode scancode)
{
    switch (sym) {
        case SDLK_DOWN:
            player.setVel(glm::vec3(0, 0, 0));
            break;
            
        case SDLK_UP:
            player.setVel(glm::vec3(0, 0, 0));
            break;
            
        case SDLK_RIGHT:
            player.setAVel(glm::vec3(0, 0, 0));
            break;
            
        case SDLK_LEFT:
            player.setAVel(glm::vec3(0, 0, 0));
            break;
            
        default:
            break;
    }
}

/***********************************************************************
 * OnLButtonDown: Speed up time.
 *
 * x:         X coordinate, relative to window.
 *
 * y:         Y coordinate, relative to window.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnLButtonDown(int x, int y)
{
    /** Speed up time. **/
    mainClock->setTimeScale(mainClock->getTimeScale() * 2);
}

/***********************************************************************
 * OnRButtonDown: Slow down time.
 *
 * x:         X coordinate, relative to window.
 *
 * y:         Y coordinate, relative to window.
 *
 * returns:   void.
***********************************************************************/
void FGame::OnRButtonDown(int x, int y)
{
    /** Speed up time. **/
    mainClock->setTimeScale(mainClock->getTimeScale() / 2);
}
