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

#include "Events.h"

/***********************************************************************
 * Events:    Constructor (does nothing).
***********************************************************************/
Events::Events()
{
    /** Do Nothing. **/
}

/***********************************************************************
 * Events:    Destructor (does nothing).
***********************************************************************/
Events::~Events()
{
    /** Do Nothing. **/
}

/***********************************************************************
 * OnEvent:   Translates SDL events to functions.
 *
 * event:     The event caused by user (ex. button press, mouse etc.).
 *
 * returns:   void.
***********************************************************************/
void Events::OnEvent(SDL_Event *event)
{
    /** See which type of event we are handling. **/
    switch(event->type)
    {
        /** Window events. **/
        case SDL_WINDOWEVENT:
        {
            switch(event->window.event)
            {
                /** Window has gained mouse focus. **/
                case SDL_WINDOWEVENT_ENTER:
                {
                    OnMouseFocus();
                    break;
                }
                /** Window has lost mouse focus. **/
                case SDL_WINDOWEVENT_LEAVE:
                {
                    OnMouseBlur();
                    break;
                }
                /** Window has gained keyboard focus. **/
                case SDL_WINDOWEVENT_FOCUS_GAINED:
                {
                    OnInputFocus();
                    break;
                }
                /** Window has lost keyboard focus. **/
                case SDL_WINDOWEVENT_FOCUS_LOST:
                {
                    OnInputBlur();
                    break;
                }
                /** Window has been restored. **/
                case SDL_WINDOWEVENT_RESTORED:
                {
                    OnRestore();
                    break;
                }
                /** Window has been minimized. **/
                case SDL_WINDOWEVENT_MINIMIZED:
                {
                    OnMinimize();
                    break;
                }
                /** Window should be closed (in turn, exit application). **/
                case SDL_WINDOWEVENT_CLOSE:
                {
                    event->type = SDL_QUIT;
                    SDL_PushEvent(event);
                    break;
                }
                /** Window size has been changed. **/
                case SDL_WINDOWEVENT_SIZE_CHANGED:
                {
                    OnResize(event->window.data1, event->window.data2);
                    break;
                }
                /** Window is exposed and should be redrawn. **/
                case SDL_WINDOWEVENT_EXPOSED:
                {
                    OnExpose();
                    break;
                }
            }
            break;
        }
        /** Key on keyboard is pressed. **/
        case SDL_KEYDOWN:
        {
            OnKeyDown(event->key.keysym.sym, event->key.keysym.mod,
                      event->key.keysym.scancode);
            break;
        }
        /** Key on keyboard is released. **/
        case SDL_KEYUP:
        {
            OnKeyUp(event->key.keysym.sym, event->key.keysym.mod,
                    event->key.keysym.scancode);
            break;
        }
        /** Mouse is moved. **/
        case SDL_MOUSEMOTION:
        {
            OnMouseMove(event->motion.x, event->motion.y, event->motion.xrel,
                     event->motion.yrel,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_LEFT))   != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_RIGHT))  != 0,
                    (event->motion.state & SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
            break;
        }
        /** A mouse button is pressed. **/
        case SDL_MOUSEBUTTONDOWN:
        {
            switch(event->button.button)
            {
                /** Left mouse button is pressed. **/
                case SDL_BUTTON_LEFT:
                {
                    OnLButtonDown(event->button.x, event->button.y);
                    break;
                }
                /** Right mouse button is pressed. **/
                case SDL_BUTTON_RIGHT:
                {
                    OnRButtonDown(event->button.x, event->button.y);
                    break;
                }
                /** Middle mouse button is pressed. **/
                case SDL_BUTTON_MIDDLE:
                {
                    OnMButtonDown(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }
        /** A mouse button is released. **/
        case SDL_MOUSEBUTTONUP:
        {
            switch(event->button.button)
            {
                /** Left mouse button is released. **/
                case SDL_BUTTON_LEFT:
                {
                    OnLButtonUp(event->button.x, event->button.y);
                    break;
                }
                /** Right mouse button is released. **/
                case SDL_BUTTON_RIGHT:
                {
                    OnRButtonUp(event->button.x, event->button.y);
                    break;
                }
                /** Middle mouse button is released. **/
                case SDL_BUTTON_MIDDLE:
                {
                    OnMButtonUp(event->button.x, event->button.y);
                    break;
                }
            }
            break;
        }
        /** Mouse wheel is scrolled up or down. **/
        case SDL_MOUSEWHEEL:
        {
            OnMouseWheel(event->wheel.x, event->wheel.y);
            break;
        }
        /** Controller axis is moved. **/
        case SDL_CONTROLLERAXISMOTION:
        {
            OnConAxis(event->caxis.which, event->caxis.axis,
                      event->caxis.value);
            break;
        }
        /** Controller button is pressed. **/
        case SDL_CONTROLLERBUTTONDOWN:
        {
            OnConButtonDown(event->cbutton.which, event->cbutton.button);
            break;
        }
        /** Controller button is released. **/
        case SDL_CONTROLLERBUTTONUP:
        {
            OnConButtonUp(event->cbutton.which, event->cbutton.button);
            break;
        }
        /** Joystick axis is moved. **/
        case SDL_JOYAXISMOTION:
        {
            OnJoyAxis(event->jaxis.which, event->jaxis.axis,
                      event->jaxis.value);
            break;
        }
        /** Trackball on the joystick is moved. **/
        case SDL_JOYBALLMOTION:
        {
            OnJoyBall(event->jball.which, event->jball.ball, event->jball.xrel,
                      event->jball.yrel);
            break;
        }
        /** Hat on the joystick is moved. **/
        case SDL_JOYHATMOTION:
        {
            OnJoyHat(event->jhat.which, event->jhat.hat, event->jhat.value);
            break;
        }
        /** Joystick is pressed. **/
        case SDL_JOYBUTTONDOWN:
        {
            OnJoyButtonDown(event->jbutton.which, event->jbutton.button);
            break;
        }
        /** Joystick is released. **/
        case SDL_JOYBUTTONUP:
        {
            OnJoyButtonUp(event->jbutton.which, event->jbutton.button);
            break;
        }
        /** Application should quit. **/
        case SDL_QUIT:
        {
            OnExit();
            break;
        }
        /** User defined event. **/
        default:
        {
            OnUser(event->user.type, event->user.code, event->user.data1,
                   event->user.data2);
            break;
        }
    }
}

/***********************************************************************
 * OnInputFocus: Called when window has gained keyboard focus (does
 *            nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnInputFocus()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnInputBlur: Called when window has lost keyboard focus (does
 *            nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnInputBlur()
{
    /** Do Nothing (pure virtual). **/
}




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
void Events::OnKeyDown(SDL_Keycode sym, Uint16 mod,
                       SDL_Scancode scancode)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnKeyUp(SDL_Keycode sym, Uint16 mod,
                     SDL_Scancode scancode)
{
    /** Do Nothing (pure virtual). **/
}




/***********************************************************************
 * OnMouseFocus: Called when window has gained mouse focus (does
 *            nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnMouseFocus()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnMouseBlur: Called when window has lost mouse focus (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnMouseBlur()
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnMouseMove(int x, int y, int xrel, int yrel,
                         bool left, bool right, bool middle)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnMouseWheel(bool x, bool y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnLButtonDown(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnLButtonUp(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnRButtonDown(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnRButtonUp(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnMButtonDown(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnMButtonUp(int x, int y)
{
    /** Do Nothing (pure virtual). **/
}




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
void Events::OnConAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnConButtonDown(SDL_JoystickID which, Uint8 button)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnConButtonUp(SDL_JoystickID which, Uint8 button)
{
    /** Do Nothing (pure virtual). **/
}




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
void Events::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value)
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnJoyButtonDown: Called when the joystick is pressed (does nothing).
 *
 * which:     The index of the joystick that reported the event.
 *
 * button:    The index of the button that changed.
 *
 * returns:   void.
***********************************************************************/
void Events::OnJoyButtonDown(Uint8 which, Uint8 button)
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnJoyButtonUp: Called when the joystick is released (does nothing).
 *
 * which:     The index of the joystick that reported the event.
 *
 * button:    The index of the button that changed.
 *
 * returns:   void.
***********************************************************************/
void Events::OnJoyButtonUp(Uint8 which, Uint8 button)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnJoyHat(Uint8 which, Uint8 hat, Uint8 value)
{
    /** Do Nothing (pure virtual). **/
}

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
void Events::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel)
{
    /** Do Nothing (pure virtual). **/
}




/***********************************************************************
 * OnMinimize: Called when the window has been minimized (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnMinimize()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnRestore: Called when the window has been restored (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnRestore()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnResize:  Called when the window size has been changed (does
 *            nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnResize(int width, int height)
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnExpose:  Called when the window is exposed and should be redrawn
 *            (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnExpose()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnExit:    Called when the application should exit (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnExit()
{
    /** Do Nothing (pure virtual). **/
}

/***********************************************************************
 * OnUser:    User defined event (does nothing).
 *
 * returns:   void.
***********************************************************************/
void Events::OnUser(Uint8 type, int code, void *data1, void *data2)
{
    /** Do Nothing (pure virtual). **/
}

