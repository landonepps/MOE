/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * This class handles in-game music
 *
 ******************************************************************************/

#ifndef __MOE__Audio__
#define __MOE__Audio__

#ifdef _MSC_VER
#include <SDL_mixer.h>
#else
#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif
#endif

class Music {
    // pointer to the music
    Mix_Music *music;
    
public:
    /*
     * Constructor for Music
     */
    Music();
    /*
     * Destructor for Music
     */
    ~Music();
    
    /*
     * loadMusic:  loads an mp3 or wav file for in game music
     *
     * filename:  path to mp3/wav file
     *
     * returns: void
     */
    void loadMusic(const char *filename);
    
    /*
     * play: plays and automatically loops the loaded music
     */
    void play();
    /*
     * stop: stops the loaded music
     */
    void stop();
};

#endif /* defined(__MOE__Audio__) */
