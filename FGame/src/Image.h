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

#ifndef __MOE__Image__
#define __MOE__Image__

#ifdef _MSC_VER
#include <SDL.h>
#include <Windows.h>
#include <GL/gl.h>
#include <GL/GLU.h>
#include <SDL_image.h>
#else
#include <SDL2/SDL.h>
#ifdef __APPLE__
#include <OpenGL/GL.h>
#include <OpenGL/GLU.h>
#include <SDL2_image/SDL_image.h>
#else
#include <GL/GL.h>
#include <GL/GLU.h>
#include <SDL2/SDL_image.h>
#endif
#endif

class Image {
private:
    SDL_Texture *texture;
    SDL_Renderer *renderer;
    
public:
    GLuint openglTex;

    /***************************************************************************
     * Image: Constructor for Image
     **************************************************************************/
    Image();
    
    /***************************************************************************
     * ~Image: Destructor for Image
     **************************************************************************/
    ~Image();
    
    /***************************************************************************
     * loadImage: loads an image file into an SDL texture
     *
     * filename: the name (path) of the image file to be loaded (bmp, jpg, png)
     * destination: the SDL_Renderer that the texture will be drawn to
     *
     * returns: void
     **************************************************************************/
    void loadImage(const char* filename, SDL_Renderer *renderer);
    
    /***************************************************************************
     * draw: draws the image to the renderer specified in loadImage
     *
     * x: the x-coordinate for the image to be drawn to
     * y: the y-coordinate for the image to be drawn to
     **************************************************************************/
    void draw(int x, int y);
    
    /***************************************************************************
     * draw: draws the image to the renderer specified in loadImage
     *
     * x: the x-coordinate for the image to be drawn to
     * y: the y-coordinate for the image to be drawn to
     * srcX: the x-coordinate to start copying to the renderer
     * srcY: the y-coordinate to start copying to the renderer
     * w: the width of the image to copy to the renderer
     * h: the height of the image to copy to the renderer
     **************************************************************************/
    void draw(int x, int y, int srcX, int srcY, int h, int w);

    /***************************************************************************
     * initTexture: initializes a texture to be used with opengl
     *
     * filename: the files name and location
     **************************************************************************/
    void initTexture(const char *filename);
};

#endif /* defined(__MOE__Image__) */
