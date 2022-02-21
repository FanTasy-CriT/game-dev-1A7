#include "header.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos,const char * path)
{
pos.x=0;
pos.y=0;
pos.h=0;
pos.w=0;
SDL_Surface *image;
//Load the BMP file into a surface 
image = SDL_LoadBMP(path);
if (image == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
return;
}
//Blit onto the screen surface 
if(SDL_BlitSurface(image, NULL, screen, &pos)){
printf("BlitSurface error: %s\n", SDL_GetError());
}
SDL_Flip(screen);
}
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path){
{
SDL_Surface *image;
//Load the BMP file into a surface 
image = IMG_Load(path);
if (image == NULL) {
printf("Couldnt load : %s\n", SDL_GetError());
return;
}
//Blit onto the screen surface 
if(SDL_BlitSurface(image, NULL, screen, &pos)){
printf("BlitSurface error: %s\n", SDL_GetError());
}
SDL_Flip(screen);
}
}
void initialize_audio(Mix_Music * music){
    if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1){
    printf("%s",SDL_GetError());
    
}
music=Mix_LoadMUS("CODEX Installer Music .mp3");
Mix_PlayMusic(music,1);
Mix_VolumeMusic(MIX_MAX_VOLUME/3.5);
}
 void PrintKeyInfo( SDL_KeyboardEvent *key ){
        /* Is it a release or a press? */
        if( key->type == SDL_KEYUP )
            printf( "Release: " );
        else
            printf( "Press: " );
        /* Print the name of the key */
        printf( "%s", SDL_GetKeyName( key->keysym.sym ) );
        printf( "\n" );
    }
void hover(int possition,SDL_Rect posmenu,SDL_Rect posmenu1,SDL_Rect posmenu2,SDL_Rect posmenu3,SDL_Surface* screen){
    switch(possition){
    case 1:
        display_img(screen,posmenu,"playhover.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quit.png");
    break;
    case 2:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"optionshover.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quit.png");
    break;
    case 3:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"creditshover.png");
        display_img(screen,posmenu3,"quit.png");
    break;
    case 4:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quithover.png");
    break;
    case 0:
    display_img(screen,posmenu,"play.png");
    display_img(screen,posmenu1,"options.png");
    display_img(screen,posmenu2,"credits.png");
    display_img(screen,posmenu3,"quit.png");
    break;
}
//Game-Button-Sounds-Pack-Free-Sounds-_AudioTrimmer.com_.wav
}
void write_texte(TTF_Font* font,SDL_Color colorblack,SDL_Surface* text,SDL_Rect textpos,SDL_Surface* screen){
TTF_Init();
font=TTF_OpenFont("Ubuntu-B.ttf",15);
text =TTF_RenderText_Blended(font,"© 2021-2022 All Rights Reserved",colorblack);
SDL_BlitSurface(text, NULL, screen, &textpos); 
SDL_Flip(screen);
TTF_CloseFont(font);
TTF_Quit();
}


int menu_loop(SDL_Event test_event,SDL_Rect posmenu1,SDL_Rect posmenu2,SDL_Rect posmenu3,SDL_Rect posmenu,SDL_Surface* screen){
Mix_Chunk * son;
int position =0;
SDL_Rect pos;
SDL_Colour colorblack={0,0,0};
TTF_Font* font;
SDL_Surface* text;
SDL_Rect textpos;
textpos.x=200;
textpos.y=390;
textpos.w=0;
textpos.h=0;
write_texte(font,colorblack,text,textpos, screen);
hover(0,posmenu,posmenu1,posmenu2,posmenu3,screen);
char filename[50];
int current=1;
int j=1;
while(1){
    if(j>500 && current==0){
    display_bmp(screen,pos,"1.bmp");
    hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
    current=1;
    }
    if(j<500 && current==1){
    display_bmp(screen,pos,"2.bmp");
    current=0;
    hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
    }
    if(j>1000){
        j=1;
    }
    j++;
    SDL_Delay(2);
while(SDL_PollEvent(&test_event)) {
//handeling hovering on buttons using mouse
switch(test_event.type) {
    case SDL_MOUSEMOTION:
            if(test_event.motion.y<=120 && test_event.motion.y>=80 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=1){ position=1;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                play_effect(son);}
            }
            else if(test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213){
                if(position!=2){ position=2;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                
                play_effect(son);
                }
            }
            else if(test_event.motion.y<=240 && test_event.motion.y>=195 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=3){ position=3;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                
                play_effect(son);}
            }
            else if(test_event.motion.y<=300 && test_event.motion.y>=255 &&(test_event.motion.x<=423 && test_event.motion.x>=213)){
                if(position!=4){ position=4;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                
                play_effect(son);}
            }
            else {
                if(position!=0){ position=0;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                }
            }
        break;

    //handeling clicking on buttons using mouse



    case SDL_MOUSEBUTTONDOWN:
    if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=120 && test_event.motion.y>=80 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click play");
        return 1;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=181 && test_event.motion.y>=136 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("clicked options");
        //never quit loop till pressed return
        //display_img(screen,posoptions,"optionsmenu.png");
        return 2;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=240 && test_event.motion.y>=195 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click credits");
        return 3;
    }
    else if(test_event.button.button==SDL_BUTTON_LEFT && (test_event.motion.y<=300 && test_event.motion.y>=255 && test_event.motion.x<=423 && test_event.motion.x>=213)){
        puts("click quits");
        SDL_Quit();
        //shutdown all sub systems
        return -1;
        printf("Quiting....\n");
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
                
                play_effect(son);
            }
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"up")==0){
                if(position>1)position--;
                hover(position,posmenu,posmenu1,posmenu2,posmenu3,screen);
                
                play_effect(son);
            }

            //handeling entering a menu element using enter button
            if(strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"return")==0 || strcmp(SDL_GetKeyName(test_event.key.keysym.sym),"enter")==0){
            switch(position){
                case 1:
                puts("pressed enter on play");
                return 1;
                break;
                case 2:
                puts("pressed enter on options");
                return 2;
                break;
                case 3:
                puts("pressed enter on credits");
                return 3;
                break;
                case 4:
                puts("pressed enter on quit");
                return -1;
                SDL_Quit();
                //shutdown all sub systems
                printf("Quiting....\n");
                break;
            }
            }
    break;

    /* SDL_QUIT event (window close) */
    case SDL_QUIT:
        SDL_Quit();
        return -1;
        //shutdown all sub systems
        printf("Quiting....\n");
        break;
}
}
}
}
void play_effect(Mix_Chunk* son){
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
son = Mix_LoadWAV("simple.wav");
if(son==NULL) printf("%s",SDL_GetError());
Mix_VolumeChunk(son,MIX_MAX_VOLUME/2.5);
Mix_PlayChannel(-1,son,0);
}