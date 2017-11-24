/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * This class handles in-game sound effects (SFX)
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
    
    /*
     * channelFinished: * NEVER * call this manually
     *
     * this is only used as an callback for Mix_ChannelFinished
     *
     */
    static void channelFinished(int channel);
public:
    /*
     * Constructor for SFX
     */
    SFX();
    /*
     * Destructor for SFX
     */
    ~SFX();
    
    /*
     * loadSFX:  loads an wav file for sound effects
     *
     * filename:  path to wav file
     *
     * returns: void
     */
    void loadSFX(const char *filename);
    
    /*
     * play: plays the sound effect and stops previously playing sound effect
     *       if necessary; does not stop SFX from other instances of this class
     */
    void play();
    
    /*
     * stop: stops previously playing sound effect if necessary;
     *       does not stop SFX from other instances of this class
     */
    void stop();
};

#endif /* defined(__MOE__SFX__) */
