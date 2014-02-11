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

#include "Music.h"
#include <iostream>

using namespace std;

Music::Music() {
    music = NULL;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "SDL_mixer could not be started: " << Mix_GetError() << endl;
    }
}

Music::~Music() {
    Mix_FreeMusic(music);
}

void Music::loadMusic(const char *filename) {
    music = Mix_LoadMUS(filename);
    if (music == NULL) {
        cerr << "Error loading audio: " << filename
             << " " << Mix_GetError() << endl;
    }
}

void Music::play() {
    Mix_PlayMusic(music, -1);
}

void Music::stop() {
    Mix_HaltMusic();
}