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


#ifndef __MOE__SFX__
#define __MOE__SFX__

#ifdef _MSC_VER
#include <SDL_mixer.h>
#else
#ifdef __APPLE__
#include <SDL2_mixer/SDL_mixer.h>
#else
#include <SDL2/SDL_mixer.h>
#endif
#endif

class SFX {
    Mix_Chunk *sample;
    static int currentChannel;
    
    static void channelFinished(int channel);
public:
    SFX();
    ~SFX();
    
    void loadSFX(const char *filename);
    
    void play();
    void stop();
};

#endif /* defined(__MOE__SFX__) */
