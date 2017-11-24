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


#include "SFX.h"
#include "Constants.h"
#include <iostream>

using namespace std;

int SFX::currentChannel = -1;

/*
 * Constructor for SFX
 */
SFX::SFX() {
    sample = NULL;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "SDL_mixer could not be started: " << Mix_GetError() << endl;
    }
    
    Mix_AllocateChannels(NUM_AUDIO_CHANNELS);
}

/*
 * Destructor for SFX
 */
SFX::~SFX() {
    if (sample) {
        Mix_FreeChunk(sample);
    }
}

/*
 * channelFinished: * NEVER * call this manually
 * 
 * this is only used as an callback for Mix_ChannelFinished
 *
 */
void SFX::channelFinished(int channel) {
    currentChannel = -1;
}

/*
 * loadSFX:  loads an wav file for sound effects
 *
 * filename:  path to wav file
 *
 * returns: void
 */
void SFX::loadSFX(const char *filename) {
    sample = Mix_LoadWAV(filename);
    if (!sample) {
        cerr << "Error loading " << filename << " with Mix_LoadWAV: "
             << Mix_GetError() << endl;
    }
}

/*
 * play: plays the sound effect and stops previously playing sound effect
 *       if necessary; does not stop SFX from other instances of this class
 */
void SFX::play() {
    stop();
    currentChannel = Mix_PlayChannel(-1, sample, 0);
    if (currentChannel == -1) {
        cerr << "Error playing sample: " << Mix_GetError() << endl;
    }
    Mix_ChannelFinished(SFX::channelFinished);
}

/*
 * stop: stops previously playing sound effect if necessary;
 *       does not stop SFX from other instances of this class
 */
void SFX::stop() {
    if (currentChannel >= 0) {
        Mix_HaltChannel(currentChannel);
    }
}