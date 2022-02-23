#ifndef HEADER_H_   /* Include guard */
#define HEADER_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
void display_bmp(SDL_Surface* screen,SDL_Rect pos,const char * path);
void display_img(SDL_Surface* screen,SDL_Rect pos,const char * path);
void initialize_audio(Mix_Music * music);
void PrintKeyInfo( SDL_KeyboardEvent *key );
void hover(int possition,SDL_Rect posmenu,SDL_Surface* screen);
void write_texte(TTF_Font* Font,SDL_Color colorblack,SDL_Surface* text,SDL_Rect pos,SDL_Surface* screen);
int menu_loop(SDL_Event test_event,SDL_Rect posmenu,SDL_Surface* screen);
void play_effect(Mix_Chunk* son);
void live_background(SDL_Surface* screen,SDL_Rect pos,int i);
#endif // HEADER_H_