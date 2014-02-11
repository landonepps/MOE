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

#include "Music.h"
#include <iostream>

using namespace std;

/*
 * Constructor for Music
 */
Music::Music() {
    music = NULL;
    
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        cerr << "SDL_mixer could not be started: " << Mix_GetError() << endl;
    }
}

/*
 * Destructor for Music
 */
Music::~Music() {
    if (music) {
        Mix_FreeMusic(music);
    }
}

/*
 * loadMusic:  loads an mp3 or wav file for in game music
 *
 * filename:  path to mp3/wav file
 *
 * returns: void
 */
void Music::loadMusic(const char *filename) {
    music = Mix_LoadMUS(filename);
    if (music == NULL) {
        cerr << "Error loading audio: " << filename
             << " " << Mix_GetError() << endl;
    }
}

/*
 * play: plays and automatically loops the loaded music
 */
void Music::play() {
    Mix_PlayMusic(music, -1);
}

/*
 * stop: stops the loaded music
 */
void Music::stop() {
    Mix_HaltMusic();
}