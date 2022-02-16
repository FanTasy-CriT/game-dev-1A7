#include "header.h"
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <SDL/SDL_mixer.h>
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
Mix_PlayMusic(music,-1);
}