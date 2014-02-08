//
//  Image.h
//  MOE
//
//  Created by Landon Epps on 2/7/14.
//  Copyright (c) 2014 Landon Epps. All rights reserved.
//

#ifndef __MOE__Image__
#define __MOE__Image__

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class Image {
private:
    SDL_Texture *texture;
    
public:
    Image();
    ~Image();
    
    void loadImage(const char* filename, SDL_Renderer *renderer);
    
    void draw(int x, int y, SDL_Renderer *renderer);
};

#endif /* defined(__MOE__Image__) */
