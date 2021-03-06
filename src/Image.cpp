/*******************************************************************************
 *
 * Author:      Landon Epps
 *
 * Assignment:  MOE (Most Optimistic Engine)
 * Class:       4342, Sprnt 2014
 * Date:        2/8/2014
 *
 * Handles loading image files and displaying them using SDL function calls
 *
 ******************************************************************************/

#include "Image.h"
#include <iostream>

using namespace std;

/*******************************************************************************
 * Image: Constructor for Image
 ******************************************************************************/
Image::Image() {
    texture = NULL;
    renderer = NULL;
}

/*******************************************************************************
 * ~Image: Destructor for Image
 ******************************************************************************/
Image::~Image() {
    SDL_DestroyTexture(texture);
}

/*******************************************************************************
 * loadImage: loads an image file into an SDL texture
 * 
 * filename: the name (path) of the image file to be loaded (bmp, jpg, png)
 * destination: the SDL_Renderer that the texture will be drawn to
 * 
 * returns: void
 ******************************************************************************/
void Image::loadImage(const char *filename, SDL_Renderer *destination) {
    SDL_Surface *tempSurface = NULL;
    
    tempSurface = IMG_Load(filename);
    
    if (tempSurface == NULL) {
        cerr << "Error loading image file " << filename << ": "
             << IMG_GetError() << endl;
    } else {
        renderer = destination;
        texture = SDL_CreateTextureFromSurface(renderer, tempSurface);
        
        SDL_FreeSurface(tempSurface);
    }
}

/*******************************************************************************
 * draw: draws the image to the renderer specified in loadImage
 *
 * x: the x-coordinate for the image to be drawn to
 * y: the y-coordinate for the image to be drawn to
 ******************************************************************************/
void Image::draw(int x, int y) {
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dst.w, &dst.h);
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

/*******************************************************************************
 * draw: draws the image to the renderer specified in loadImage
 *
 * x: the x-coordinate for the image to be drawn to
 * y: the y-coordinate for the image to be drawn to
 * srcX: the x-coordinate to start copying to the renderer
 * srcY: the y-coordinate to start copying to the renderer
 * w: the width of the image to copy to the renderer
 * h: the height of the image to copy to the renderer
 ******************************************************************************/
void Image::draw(int x, int y, int srcX, int srcY, int w, int h) {
    const SDL_Rect dst  = { x, y, w, h };
    
    const SDL_Rect src  = { srcX, srcY, w, h };
    
    SDL_RenderCopy(renderer, texture, &src, &dst);
}
