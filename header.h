#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
void display_bmp(SDL_Surface* screen,SDL_Rect pos);
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path);
void initialize_audio(Mix_Music * music);
#endif // HEADER_H_