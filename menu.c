#include "header.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <stdio.h>

void display_bmp(SDL_Surface* screen,SDL_Rect pos)
{
pos.x=0;
pos.y=0;
pos.h=0;
pos.w=0;
SDL_Surface *image;
//Load the BMP file into a surface 
image = SDL_LoadBMP("final.bmp");
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
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path){
{
SDL_Surface *image;
//Load the BMP file into a surface 
image = IMG_Load(path);
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
    Mix_Chunk * son;
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
son = Mix_LoadWAV("simple.wav");
if(son==NULL) printf("%s",SDL_GetError());
Mix_VolumeChunk(son,MIX_MAX_VOLUME/2.5);
    switch(possition){
    case 1:
        display_img(screen,posmenu,"playhover.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quit.png");
        Mix_PlayChannel(-1,son,0);
    break;
    case 2:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"optionshover.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quit.png");
        Mix_PlayChannel(-1,son,0);
    break;
    case 3:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"creditshover.png");
        display_img(screen,posmenu3,"quit.png");
        Mix_PlayChannel(-1,son,0);
    break;
    case 4:
        display_img(screen,posmenu,"play.png");
        display_img(screen,posmenu1,"options.png");
        display_img(screen,posmenu2,"credits.png");
        display_img(screen,posmenu3,"quithover.png");
        Mix_PlayChannel(-1,son,0);
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