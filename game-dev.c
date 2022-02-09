#include "game.h"
#include "SDL/SDL_image.h"
#include <SDL/SDL.h>>/* All SDL App’s need this */
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos)
{
SDL_Surface *image;
/* Load the BMP file into a surface */
image = SDL_LoadBMP("background.bmp");
if (image == NULL) {
fprintf(stderr, "Couldn’t load : %s\n", SDL_GetError());
return;
}
/* Blit onto the screen surface */
SDL_BlitSurface(image, NULL, screen, &pos);
//fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());}
SDL_Flip(screen);
}