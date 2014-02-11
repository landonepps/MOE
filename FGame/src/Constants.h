/*******************************************************************************
 * Authors:    Jesse Clary
 *             Landon Epps
 *             Andrew Kliphon
 *             Jeremy Stark
 * Assignment: MOE (Most Optimistic Engine)
 * Class:      4342, Spring 2014
 * Date:       2/06/2014
 *
 * Contains any global constants, macros, etc. used in game.
*******************************************************************************/

#ifndef CONSTANTS_H_
#define CONSTANTS_H_

#ifdef _MSC_VER
#include <SDL.h>
#else
#include <SDL2/SDL.h>
#endif

/** Global constants will go here. **/
const Uint8 UP_DPAD          = 0;
const Uint8 DOWN_DPAD        = 1;
const Uint8 LEFT_DPAD        = 2;
const Uint8 RIGHT_DPAD       = 3;
const Uint8 START_BUTTON     = 4;
const Uint8 SELECT_BUTTON    = 5;
const Uint8 LEFT_JOY_BUTTON  = 6;
const Uint8 RIGHT_JOY_BUTTON = 7;
const Uint8 LEFT_SHOULDER    = 8;
const Uint8 RIGHT_SHOULDER   = 9;
const Uint8 A_BUTTON         = 10;
const Uint8 B_BUTTON         = 11;
const Uint8 X_BUTTON         = 12;
const Uint8 Y_BUTTON         = 13;
const Uint8 HOME_BUTTON      = 14;

const int NUM_AUDIO_CHANNELS = 16;
const int PUNCH_DMG          = 5;
const int PUNCH_REACH        = 25;

const int WIN_WIDTH          = 640;
const int WIN_HEIGHT         = 480;

/** Values for entity typing **/
enum {
    ENTITY_TYPE_GENERIC = 0,
    
    ENTITY_TYPE_PLAYER,
    
	ENTITY_TYPE_ATTACK
};

/** Values for collision typing **/
enum {
    ENTITY_FLAG_NONE = 0,
    
    ENTITY_FLAG_GRAVITY    = 0x00000001,
    ENTITY_FLAG_THRU_WALL  = 0x00000002,
    ENTITY_FLAG_NO_COLLIDE = 0x00000004
};

#endif /* CONSTANTS_H_ */
