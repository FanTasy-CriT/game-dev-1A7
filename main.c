#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include "header.h"

int main() {
SDL_Surface* screen;
SDL_Rect pos;

//initializing image position
SDL_Rect posmenu;
SDL_Rect posmenu1;
SDL_Rect posmenu2;
SDL_Rect posmenu3;
posmenu.x=140;posmenu.y=50;posmenu.h=0;posmenu.w=0;posmenu1.x=140;posmenu1.y=115;posmenu1.h=0;posmenu1.w=0;posmenu2.x=140;posmenu2.y=180;posmenu2.h=0;posmenu2.w=0;posmenu3.x=140;posmenu3.y=245;posmenu3.h=0;posmenu3.w=0;
printf("Initializing SDL.\n");
/* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
exit(-1);
}
printf("SDL initialized.\n");

//setting window
SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",
SDL_GetError());
exit(1);
}
display_bmp(screen,pos);
display_img(screen,posmenu,"play.png");
display_img(screen,posmenu1,"options.png");
display_img(screen,posmenu2,"credits.png");
display_img(screen,posmenu3,"quit.png");
SDL_Delay(2000);
printf("Quiting SDL.\n");
/* Shutdown all subsystems */
SDL_Quit();
printf("Quiting....\n");
exit(0);
}
