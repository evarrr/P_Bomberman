#include <SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"
#include "case.h"
#include "affichage.h"

int max(int c,int b){
    if(c<b){
        return b;
    }
    return c;
}

void affichage_explosion(case_t* CASE,int max_haut,int max_bas,int max_droite,int max_gauche,SDL_Renderer* renderer){
    SDL_Rect rectangle;
    if(SDL_SetRenderDrawColor(renderer,255,94,5,SDL_ALPHA_OPAQUE)!=0){
        SDL_Quit();
    }
    rectangle.h=40;
    rectangle.w=40;

    rectangle.x=7+CASE->posx*42;
    rectangle.y=7+CASE->posy*42;
    if(SDL_RenderFillRect(renderer,&rectangle)!=0)
    {
        SDL_Quit();
    }

    int maxi=max(max_haut,max_bas);
    maxi=max(maxi,max_droite);
    maxi=max(maxi,max_gauche);
    int i=1;
    while(i<=maxi){
        rectangle.y=7+CASE->posy*42;
        SDL_Delay(100);
        if(i<=max_droite){
            rectangle.x=7+(CASE->posx+i)*42;
            if(SDL_RenderFillRect(renderer,&rectangle)!=0)
            {
                SDL_Quit();
            }
        }
        if(i<=max_gauche){
            rectangle.x=7+(CASE->posx-i)*42;
            if(SDL_RenderFillRect(renderer,&rectangle)!=0)
            {
                SDL_Quit();
            }
        }
        rectangle.x=7+CASE->posx*42;
        if(i<=max_bas){
            rectangle.y=7+(CASE->posy-i)*42;
            if(SDL_RenderFillRect(renderer,&rectangle)!=0)
            {
                SDL_Quit();
            }
        }
        if(i<=max_haut){
            rectangle.y=7+(CASE->posy+i)*42;
            if(SDL_RenderFillRect(renderer,&rectangle)!=0)
            {
                SDL_Quit();
            }
        }
        SDL_RenderPresent(renderer);
        ++i;
    }
    SDL_Delay(500);

    if(SDL_SetRenderDrawColor(renderer,0,0,0,SDL_ALPHA_OPAQUE)!=0){
        SDL_Quit();
    }
    rectangle.x=7+CASE->posx*42;
    rectangle.y=7+CASE->posy*42;
    if(SDL_RenderFillRect(renderer,&rectangle)!=0)
    {
        SDL_Quit();
    }
    i=1;
    while(i<=max_haut){
        rectangle.y=7+(CASE->posy+i)*42;
        if(SDL_RenderFillRect(renderer,&rectangle)!=0)
        {
            SDL_Quit();
        }
        ++i;
    }
    i=1;
    while(i<=max_bas){
        rectangle.y=7+(CASE->posy-i)*42;
        if(SDL_RenderFillRect(renderer,&rectangle)!=0)
        {
            SDL_Quit();
        }
        ++i;
    }
    i=1;
    rectangle.y=7+CASE->posy*42;
    while(i<=max_droite){
        rectangle.x=7+(CASE->posx+i)*42;
        if(SDL_RenderFillRect(renderer,&rectangle)!=0)
        {
            SDL_Quit();
        }
        ++i;
    }
    i=1;
    while(i<=max_gauche){
        rectangle.x=7+(CASE->posx-i)*42;
        if(SDL_RenderFillRect(renderer,&rectangle)!=0)
        {
            SDL_Quit();
        }
        ++i;
    }
    SDL_Delay(1500);
}

void affichage_joueur_1(map_t map,joueur_t joueur1,SDL_Renderer* renderer)
{
    if(SDL_SetRenderDrawColor(renderer,100,100,255,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }
    SDL_Rect rectangle;
    rectangle.w=20;
    rectangle.h=20;
    int x=joueur1.posx;
    int y=joueur1.posy;
    rectangle.x=17+42*x;
    rectangle.y=17+42*y;
    if(SDL_RenderFillRect(renderer,&rectangle)!=0)
    {
        SDL_Quit();
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(200);
}