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
#include "Constants.h"
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
    if (button == RIGHT_SHOULDER)
    {
        player.setVelY(-50);
    }
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
    if (button == RIGHT_SHOULDER)
    {
        player.setVelY(50);
    }
}

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
void FGame::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    /** We want to retain values between OnJoyAxis calls. **/
    static double movX = 0;
    static double movZ = 0;
    static double rotY = 0;
    static double rotX = 0;

    /** If left joystick left/right. **/
    if(axis == LEFT_AXIS_HOR)
    {
        /** Make sure joystick has exceeded threshold in either
         *  direction. **/
        if(value < -AXIS_THRESHOLD || value > AXIS_THRESHOLD)
        {
            /** Scale transformation based on how far joystick is pushed.
             *  -1 < moxX < 1 **/
            movX = value / -AXIS_MAX;
        }
        else
        {
            movX = 0;
        }
    }

    /** If left joystick up/down. **/
    if(axis == LEFT_AXIS_VER)
    {
        /** Make sure joystick has exceeded threshold in either
         *  direction. **/
        if(value < -AXIS_THRESHOLD || value > AXIS_THRESHOLD)
        {
            /** Scale transformation based on how far joystick is pushed.
             *  -1 < moxZ < 1 **/
            movZ = value / -AXIS_MAX;
        }
        else
        {
            movZ = 0;
        }
    }

    /** If right joystick left/right. **/
    if(axis == RIGHT_AXIS_HOR)
    {
        /** Make sure joystick has exceeded threshold in either
         *  direction. **/
        if(value < -AXIS_THRESHOLD || value > AXIS_THRESHOLD)
        {
            /** Scale transformation based on how far joystick is pushed.
             *  -1 < rotY < 1. **/
            rotY = value / AXIS_MAX;
        }
        else
        {
            rotY = 0;
        }
    }

    /** If right joystick up/down. **/
    if(axis == RIGHT_AXIS_VER)
    {
        /** Make sure joystick has exceeded threshold in either
         *  direction. **/
        if(value < -AXIS_THRESHOLD || value > AXIS_THRESHOLD)
        {
            /** Scale transformation based on how far joystick is pushed.
             *  -1 < rotX < 1 **/
            rotX = value / AXIS_MAX;
        }
        else
        {
            rotX = 0;
        }
    }

    /** Apply transformations to player. **/
    GLfloat oldYVel = player.getVel().y;
    player.setVel(glm::vec3(movX * MOVE_SPEED, oldYVel, movZ * MOVE_SPEED));
    player.setAVel(glm::vec3(rotX * ROT_SPEED, rotY * ROT_SPEED, 0));
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
            player.setVel(glm::vec3(0, 0, -100));
            break;
            
        case SDLK_UP:
            player.setVel(glm::vec3(0, 0, 100));
            break;
            
        case SDLK_RIGHT:
            player.setAVel(glm::vec3(0, 40, 0));
            break;
        
        case SDLK_LEFT:
            player.setAVel(glm::vec3(0, -40, 0));
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
    GLfloat oldYVel = player.getVel().y;
    
    switch (sym) {
        case SDLK_DOWN:
            player.setVel(glm::vec3(0, oldYVel, 0));
            break;
            
        case SDLK_UP:
            player.setVel(glm::vec3(0, oldYVel, 0));
            break;
            
        case SDLK_RIGHT:
            player.setAVel(glm::vec3(0, oldYVel, 0));
            break;
            
        case SDLK_LEFT:
            player.setAVel(glm::vec3(0, oldYVel, 0));
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
    /** Toggle hitboxes. **/
    hitbox = !hitbox;
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

}
