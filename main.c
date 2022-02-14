#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

int main() {
SDL_Surface* screen;
SDL_Rect pos;
//initializing image position
pos.x=0;
pos.y=0;
pos.h=0;
pos.w=0;
printf("Initializing SDL.\n");
/* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
exit(-1);
}
printf("SDL initialized.\n");

//setting window
screen = SDL_SetVideoMode(640, 410, 32, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",
SDL_GetError());
exit(1);
}
initialize_audio();
display_bmp(screen,pos);
SDL_Delay(500);
printf("Quiting SDL.\n");
/* Shutdown all subsystems */
SDL_Quit();
printf("Quiting....\n");
exit(0);
}