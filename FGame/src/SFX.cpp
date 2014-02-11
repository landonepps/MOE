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


#include "SFX.h"
#include "Constants.h"
#include <iostream>

using namespace std;

int SFX::currentChannel = -1;

SFX::SFX() {
    sample = NULL;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "SDL_mixer could not be started: " << Mix_GetError() << endl;
    }
    
    Mix_AllocateChannels(NUM_AUDIO_CHANNELS);
}

SFX::~SFX() {
    if (sample) {
        Mix_FreeChunk(sample);
    }
}

void SFX::channelFinished(int channel) {
    currentChannel = -1;
}


void SFX::loadSFX(const char *filename) {
    sample = Mix_LoadWAV(filename);
    if (!sample) {
        cerr << "Error loading " << filename << " with Mix_LoadWAV: "
             << Mix_GetError() << endl;
    }
}

void SFX::play() {
    stop();
    currentChannel = Mix_PlayChannel(-1, sample, 0);
    if (currentChannel == -1) {
        cerr << "Error playing sample: " << Mix_GetError() << endl;
    }
    Mix_ChannelFinished(SFX::channelFinished);
}

void SFX::stop() {
    if (currentChannel >= 0) {
        Mix_HaltChannel(currentChannel);
    }
}