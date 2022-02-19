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
SDL_Rect posmenu3;
posmenu.x=200;posmenu.y=70;posmenu.h=0;posmenu.w=0;posmenu1.x=200;posmenu1.y=130;posmenu1.h=0;posmenu1.w=0;posmenu2.x=200;posmenu2.y=190;posmenu2.h=0;posmenu2.w=0;posmenu3.x=200;posmenu3.y=250;posmenu3.h=0;posmenu3.w=0;

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
display_bmp(screen,pos);
SDL_Surface* text;
SDL_Colour colorblack={177,185,236};
TTF_Font* font;
SDL_Rect textpos;
textpos.x=195;
textpos.y=390;
textpos.w=0;
textpos.h=0;
write_texte(font,colorblack,text,textpos, screen);
hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
SDL_Event test_event;


printf("menu inintialized!\n");
printf("listening on events ...\n");

while(1){
while(SDL_PollEvent(&test_event)) {

//handeling hovering on buttons using mouse


switch(test_event.type) {
    case SDL_MOUSEMOTION:
    printf("%d %d \n",test_event.motion.x,test_event.motion.y);
            if(test_event.motion.y<=120 && test_event.motion.y>=80 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=1){ position=1;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);}
            }
            else if(test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213){
                if(position!=2){ position=2;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);}
            }
            else if(test_event.motion.y<=240 && test_event.motion.y>=195 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=3){ position=3;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);}
            }
            else if(test_event.motion.y<=300 && test_event.motion.y>=255 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=4){ position=4;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);}
            }
            else {
                if(position!=0){ position=0;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);}
            }
        break;

    //handeling clicking on buttons using mouse



    case SDL_MOUSEBUTTONDOWN:
    if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=120 && test_event.motion.y>=80 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click play");
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213)){
         puts("clicked options");
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=240 && test_event.motion.y>=195 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click credits");
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=300 && test_event.motion.y>=255 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click quits");
        SDL_Quit();
        //shutdown all sub systems
        printf("Quiting....\n");
        return 0;
    }
    else puts("unrecognized click");
        break;



    case SDL_KEYDOWN:
    //SDL_WM_ToggleFullScreen(screen);
        PrintKeyInfo(&test_event.key); //printing pressed or released button name
            //handeling switch menu element using up and down buttons
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"down")==0){
                if(position<4)position++;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
            }
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"up")==0){
                if(position>1)position--;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
            }

            //handeling entering a menu element using enter button
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"return")==0 || strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"enter")==0){
            switch(position){
                case 1:
                puts("pressed enter on play");
                break;
                case 2:
                puts("pressed enter on options");
                break;
                case 3:
                puts("pressed enter on credits");
                break;
                case 4:
                puts("pressed enter on quit");
                SDL_Quit();
                //shutdown all sub systems
                printf("Quiting....\n");
                return 0;
                break;
            }
            }
    break;

    /* SDL_QUIT event (window close) */
    case SDL_QUIT:
        SDL_Quit();
        //shutdown all sub systems
        printf("Quiting....\n");
        return 0;
        break;
}
}
}
}