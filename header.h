#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
void display_bmp(SDL_Surface* screen,SDL_Rect pos);
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path);
void initialize_audio(Mix_Music * music);
void PrintKeyInfo( SDL_KeyboardEvent *key );
void hover(int possition,SDL_Rect posmenu,SDL_Rect posmenu1,SDL_Rect posmenu2,SDL_Rect posmenu3,SDL_Surface* screen);
#endif // HEADER_H_