#ifndef MINIMAP_H_   /* Include guard */
#define MINIMAP_H_
#include <SDL/SDL_image.h>
#include <SDL/SDL.h>/* All SDL App’s need this */
#include <stdio.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "header.h"
#include <string.h>
typedef struct{
SDL_Surface* image;
SDL_Rect pos;
SDL_Surface* player;
SDL_Rect pos_p;
}minimap;
typedef struct  {
    SDL_Surface* textSurface;
    SDL_Rect positionText;
    char txt[20];
    SDL_Color couleurTxt;
    TTF_Font* police;
}Text;// structure text besh tekteb l temps 
typedef struct
{
    int tempsdebut;
    int mm; 
    int ss;
    char temps[20];
} Time;
typedef struct{
    SDL_Rect pos_diag;
    SDL_Surface* diag;
    char text[256];
}Boite;
void affichier_diag(Boite b,SDL_Surface* screen);
void inittemps(Time *t);
void Timer(int *tempsdebut);
void update_time(Time* T,SDL_Surface* screen);
void update_timeenig(Time* T,SDL_Surface* screen);
void MAJMinimap(SDL_Rect posJoueur,minimap* m,SDL_Rect camera,int redimensionnement);
void afficher (minimap m, SDL_Surface * screen);
int enter_player_name(SDL_Surface* screen,char* player_name,SDL_Event test_event,Time* t);
void afficher_scoreboard (SDL_Surface* screen);
void save_score(char nom_joueur[],int score);
void init_minimap(minimap* m);
#endif // MINIMAP_H_
