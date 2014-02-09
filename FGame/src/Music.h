/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 *
 *
 ******************************************************************************/

#ifndef __MOE__Audio__
#define __MOE__Audio__


#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif

class Music {
    Mix_Music *music;
    
public:
    Music();
    ~Music();
    
    void loadMusic(const char *filename);
    void playMusic();
    void stopMusic();
};

#endif /* defined(__MOE__Audio__) */
