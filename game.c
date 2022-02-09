
#include "SDL/SDL_image.h"
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos);

int main() {
int  done =0;
SDL_Surface* screen;
SDL_Rect pos;
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

screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",
SDL_GetError());
exit(1);
}

//char file[]="images.bmp";
while(done<10000){ 
display_bmp(screen,pos);
done++;}

printf("Quiting SDL.\n");
/* Shutdown all subsystems */
SDL_Quit();
printf("Quiting....\n");
exit(0);
}



void display_bmp(SDL_Surface* screen,SDL_Rect pos)
{
SDL_Surface *image;
/* Load the BMP file into a surface */
image = SDL_LoadBMP("blabla.bmp");
if (image == NULL) {
fprintf(stderr, "Couldn’t load : %s\n", SDL_GetError());
return;
}
/* Blit onto the screen surface */
SDL_BlitSurface(image, NULL, screen, &pos);
//fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());}
SDL_Flip(screen);
}