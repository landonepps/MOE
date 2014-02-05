/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/04/2014
 *
 * Translates SDL events to functions.
*******************************************************************************/

#ifndef EVENTS_H_
#define EVENTS_H_

#include <SDL2/SDL.h>   /** Contains all necessary SDL functions (ver 2). **/

class Events
{
    public:
        /***********************************************************************
         * Events:    Constructor (does nothing).
        ***********************************************************************/
        Events();

        /***********************************************************************
         * Events:    Destructor (does nothing).
        ***********************************************************************/
        virtual ~Events();

        /***********************************************************************
         * OnEvent:   Translates SDL events to functions.
         *
         * event:     The event caused by user (ex. button press, mouse etc.).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnEvent(SDL_Event *event);




        /***********************************************************************
         * OnInputFocus: Called when window has gained keyboard focus (does
         *            nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnInputFocus();

        /***********************************************************************
         * OnInputBlur: Called when window has lost keyboard focus (does
         *            nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnInputBlur();




        /***********************************************************************
         * OnKeyDown: Called when key on keyboard is pressed (does nothing).
         *
         * sym:       The SDL virtual key representation.
         *
         * mod:       The SDL physical key representation.
         *
         * scancode:  Current key modifiers.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod,
                               SDL_Scancode scancode);

        /***********************************************************************
         * OnKeyUp:   Called when key on keyboard is released (does nothing).
         *
         * sym:       The SDL virtual key representation.
         *
         * mod:       The SDL physical key representation.
         *
         * scancode:  Current key modifiers.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod,
                             SDL_Scancode scancode);




        /***********************************************************************
         * OnMouseFocus: Called when window has gained mouse focus (does
         *            nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMouseFocus();

        /***********************************************************************
         * OnMouseBlur: Called when window has lost mouse focus (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMouseBlur();

        /***********************************************************************
         * OnMouseMove: Called when the mouse is moved (does nothing).
         *
         * x:         X coordinate, relative to window
         *
         * y:         Y coordinate, relative to window
         *
         * xrel:      Relative motion in the X direction
         *
         * yrel:      Relative motion in the Y direction
         *
         * left:      Whether or not the left button is pressed
         *            (true = pressed).
         *
         * right:     Whether or not the right button is pressed
         *            (true = pressed).
         *
         * middle:    Whether or not the middle button is pressed
         *            (true = pressed).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMouseMove(int x, int y, int xrel, int yrel,
                                 bool left, bool right, bool middle);

        /***********************************************************************
         * OnMouseWheel: Called when the mouse wheel is scrolled up or down
         *            (does nothing).
         *
         * x:         The amount scrolled horizontally.
         *
         * y:         The amount scrolled vertically.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMouseWheel(bool x, bool y);

        /***********************************************************************
         * OnLButtonDown: Called when the left mouse button is pressed (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnLButtonDown(int x, int y);

        /***********************************************************************
         * OnLButtonUp: Called when the left mouse button is released (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnLButtonUp(int x, int y);

        /***********************************************************************
         * OnRButtonDown: Called when the right mouse button is pressed (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnRButtonDown(int x, int y);

        /***********************************************************************
         * OnRButtonUp: Called when the right mouse button is released (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnRButtonUp(int x, int y);

        /***********************************************************************
         * OnMButtonDown: Called when the middle mouse button is pressed (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMButtonDown(int x, int y);

        /***********************************************************************
         * OnMButtonUp: Called when the middle mouse button is released (does
         *            nothing).
         *
         * x:         X coordinate, relative to window.
         *
         * y:         Y coordinate, relative to window.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMButtonUp(int x, int y);




        /***********************************************************************
         * OnConAxis: Called when the controller axis is moved (does nothing).
         *
         * which:     The joystick instance id.
         *
         * axis:      The controller axis.
         *
         * value:     The axis value (range: -32768 to 32767).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnConAxis(Uint8 which, Uint8 axis, Sint16 value);

        /***********************************************************************
         * OnConButtonDown: Called when the controller button is pressed (does
         *            nothing).
         *
         * which:     The joystick instance id.
         *
         * button:    The controller button.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnConButtonDown(SDL_JoystickID which, Uint8 button);

        /***********************************************************************
         * OnConButtonDown: Called when the controller button is released (does
         *            nothing).
         *
         * which:     The joystick instance id.
         *
         * button:    The controller button.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnConButtonUp(SDL_JoystickID which, Uint8 button);




        /***********************************************************************
         * OnJoyAxis: Called when the joystick axis is moved (does nothing).
         *
         * which:     The index of the joystick that reported the event.
         *
         * axis:      The index of the axis that changed.
         *
         * value:     The current position of the axis (range: -32768 to 32767).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value);

        /***********************************************************************
         * OnJoyButtonDown: Called when the joystick is pressed (does nothing).
         *
         * which:     The index of the joystick that reported the event.
         *
         * button:    The index of the button that changed.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyButtonDown(Uint8 which, Uint8 button);

        /***********************************************************************
         * OnJoyButtonUp: Called when the joystick is released (does nothing).
         *
         * which:     The index of the joystick that reported the event.
         *
         * button:    The index of the button that changed.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyButtonUp(Uint8 which, Uint8 button);

        /***********************************************************************
         * OnJoyHat:  Called when the hat on the joystick is moved (does
         *            nothing).
         *
         * which:     The index of the joystick that reported the event.
         *
         * hat:       The index of the hat that changed.
         *
         * value:     The new position of the hat.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyHat(Uint8 which, Uint8 hat, Uint8 value);

        /***********************************************************************
         * OnJoyBall: Called when the trackball on the joystick is moved (does
         *            nothing).
         *
         * which:     The index of the joystick that reported the event.
         *
         * ball:      The index of the hat that changed.
         *
         * xrel:      The relative motion in the X direction.
         *
         * yrel:      The relative motion in the Y direction.
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel,
                               Sint16 yrel);




        /***********************************************************************
         * OnMinimize: Called when the window has been minimized (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnMinimize();

        /***********************************************************************
         * OnRestore: Called when the window has been restored (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnRestore();

        /***********************************************************************
         * OnResize:  Called when the window size has been changed (does
         *            nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnResize(int width, int height);

        /***********************************************************************
         * OnExpose:  Called when the window is exposed and should be redrawn
         *            (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnExpose();

        /***********************************************************************
         * OnExit:    Called when the application should exit (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnExit();

        /***********************************************************************
         * OnUser:    User defined event (does nothing).
         *
         * returns:   void.
        ***********************************************************************/
        virtual void OnUser(Uint8 type, int code, void *data1, void *data2);
};

#endif /* EVENTS_H_ */
