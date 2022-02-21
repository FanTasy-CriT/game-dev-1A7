#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include <string.h>

int main() {
SDL_Surface* screen;
SDL_Rect pos;

//initializing image position
SDL_Rect posmenu;
SDL_Rect posmenu1;
SDL_Rect posmenu2;
SDL_Rect posoptions;
SDL_Rect posmenu3;
posoptions.x=167;posoptions.y=66;posmenu.x=200;posmenu.y=70;posmenu.h=0;posmenu.w=0;posmenu1.x=200;posmenu1.y=130;posmenu1.h=0;posmenu1.w=0;posmenu2.x=200;posmenu2.y=190;posmenu2.h=0;posmenu2.w=0;posmenu3.x=200;posmenu3.y=250;posmenu3.h=0;posmenu3.w=0;

printf("Initializing SDL.\n");
/* Initialize defaults, Video and Audio */
if((SDL_Init(SDL_INIT_VIDEO|SDL_INIT_AUDIO|SDL_INIT_JOYSTICK)==-1)) {
printf("Could not initialize SDL: %s.\n", SDL_GetError());
return -1;
}
printf("SDL initialized.\n");

//setting window
SDL_putenv("SDL_VIDEO_WINDOW_POS=center");
screen = SDL_SetVideoMode(640, 410, 8, SDL_SWSURFACE|SDL_ANYFORMAT);
if( screen == NULL ) {
fprintf(stderr, "Couldn’t set 640x480x8 video mode: %s\n",SDL_GetError());
return 1;
}


//playing music

Mix_Music * music;
initialize_audio(music);


int position =0; //hover position mouse
hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
SDL_Event test_event;


printf("menu inintialized!\n");
printf("listening on events ...\n");
int i=0;
int level=2;
while(1){
    int done=0;
switch(menu_loop(test_event,posmenu1,posmenu2,posmenu3,posmenu,screen)){
    case 1:
    //load play
    break;
    case 2:
    while(!(done==1)){
    display_img(screen,posoptions,"optionsmenu.png");
    while(SDL_PollEvent(&test_event)) {
        switch(test_event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if(test_event.button.button==SDL_BUTTON_RIGHT && (test_event.motion.y<=160 && test_event.motion.y>=148 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(level<=4){
                    level++;
                    Mix_VolumeMusic(MIX_MAX_VOLUME/level);
                    if(level==5)Mix_VolumeMusic(0);
                    }
                }
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=160 && test_event.motion.y>=148 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(level>=2){
                    level--;
                    Mix_VolumeMusic(MIX_MAX_VOLUME/level);
                    }
                }
                //clicked on full screen
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=197 && test_event.motion.y>=185 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(i==0){SDL_WM_ToggleFullScreen(screen);i++;}
                }
                //clicked on windowed
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=235 && test_event.motion.y>=220 && test_event.motion.x<=368 && test_event.motion.x>=352)){
                    if(i==1){SDL_WM_ToggleFullScreen(screen);i--;}
                }
                if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=110 && test_event.motion.y>=81 && test_event.motion.x<=212 && test_event.motion.x>=184)){
                    done=1;
                }
            break;
            case SDL_QUIT:
                SDL_Quit();
                //shutdown all sub systems
                return -1;
                printf("Quiting....\n");
            break;
        }
    }
    //load options
    }
    break;
    case 3:
    //load credits
    break;
    case -1: 
    return -1;
    break;
}
}
}
