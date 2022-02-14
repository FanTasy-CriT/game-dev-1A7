#include "header.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <SDL/SDL_mixer.h>
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos)
{
SDL_Surface *image;
//Load the BMP file into a surface 
image = SDL_LoadBMP("/home/fantasy/final.bmp");
if (image == NULL) {
fprintf(stderr, "Couldnt load : %s\n", SDL_GetError());
return;
}
//Blit onto the screen surface 
if(SDL_BlitSurface(image, NULL, screen, &pos)){
fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());
}
SDL_Flip(screen);
}

void initialize_audio(){

}