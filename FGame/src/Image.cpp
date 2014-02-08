//
//  Image.cpp
//  MOE
//
//  Created by Landon Epps on 2/7/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#include "Image.h"
#include <iostream>

using namespace std;

Image::Image() {
    texture = NULL;
}

Image::~Image() {
    SDL_DestroyTexture(texture);
}

void Image::loadImage(const char *filename, SDL_Renderer *renderer) {
    SDL_Surface *tempSurface = NULL;
    
    tempSurface = IMG_Load(filename);
    
    if (tempSurface == NULL) {
        cerr << "Error loading file " << filename << "." << endl;
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        
        SDL_FreeSurface(tempSurface);
    }
}

void Image::draw(int x, int y, SDL_Renderer *renderer) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}