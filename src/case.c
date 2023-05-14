#include <SDL2/SDL.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"
#include "case.h"
#include "affichage.h"

// mur = incassable, bloc = cassable

void init_mur(int taille,map_t map,SDL_Renderer* renderer){
    if(SDL_SetRenderDrawColor(renderer,128,0,0,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }
    SDL_Rect rectangle;
    rectangle.w=40;
    rectangle.h=40;
    for(int i=0;i<taille;++i){
        for(int j=0;j<taille;++j){
            map[i][j].posx=i;
            map[i][j].posy=j;
            if(i==0||i==taille-1||j==0||j==taille-1){
                map[i][j].type="mur";
                rectangle.x=7+i*42;
                rectangle.y=7+j*42;
                if(SDL_RenderFillRect(renderer,&rectangle)!=0)
                {
                    SDL_Quit();
                }

            }
            else if(i%2==0 && j%2==0){
                map[i][j].type="mur";
                rectangle.x=7+i*42;
                rectangle.y=7+j*42;
                if(SDL_RenderFillRect(renderer,&rectangle)!=0)
                {
                    SDL_Quit();
                }
            }
            else{
                map[i][j].type="vide";
            }
        }
    }
}


void init_bloc_0(int taille,map_t map,SDL_Renderer* renderer){
    if(SDL_SetRenderDrawColor(renderer,245,245,220,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }
    SDL_Rect rectangle;
    rectangle.w=40;
    rectangle.h=40;
    for(int i=2;i<taille-2;++i){
        for(int j=2;j<taille-2;++j){
            if(strcmp(map[i][j].type,"vide")==0){
                map[i][j].type="bloc";
                rectangle.x=7+i*42;
                rectangle.y=7+j*42;
                if(SDL_RenderFillRect(renderer,&rectangle)!=0)
                {
                    SDL_Quit();
                }
            }
        }
    }
    SDL_RenderPresent(renderer);
    SDL_Delay(200);
}

void init_joueur(map_t map,joueur_t* joueur_1,joueur_t* joueur_2)
{
    joueur_1->posx=1;
    joueur_1->posy=1;
    joueur_2->posx=13;
    joueur_2->posy=13;
    map[1][1].type="joueur_1";
    map[13][13].type="joueur_2";
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

void explosion(case_t* CASE,map_t map,SDL_Renderer* renderer,joueur_t* joueur1,joueur_t* joueur2){
    if(SDL_SetRenderDrawColor(renderer,255,94,5,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }
    char* type_bombe=CASE->type;
    int posx_bombe=CASE->posx;
    int posy_bombe=CASE->posy;
    int portee;
    if(strcmp(type_bombe,"bombe3cases")==0){
        portee=3;
    }
    if(strcmp(type_bombe,"bombeligne")==0){
        portee=15;
    }
    int i=1;
    // SDL_Rect rectangle;
    // rectangle.w=40;
    // rectangle.h=40;
    int max_droite=0;
    int max_gauche=0;
    int max_haut=0;
    int max_bas=0;    
    
    SDL_Delay(200);
    //regarde l'est
    while(i<=portee){
        if(strcmp(map[posx_bombe+i][posy_bombe].type,"mur")==0){
            i=portee+1;
        }
        else if(strcmp(map[posx_bombe+i][posy_bombe].type,"bloc")==0){
            i=portee+1;
            max_droite=max_droite+1;
        }
        else if(strcmp(map[posx_bombe+i][posy_bombe].type,"bonus")==0){
            i=i+1;
            max_droite=max_droite+1;
        }
        else if(strcmp(map[posx_bombe+i][posy_bombe].type,"joueur1")==0){
            i=i+1;
            max_droite=max_droite+1;
        }
        else if(strcmp(map[posx_bombe+i][posy_bombe].type,"joueur2")==0){
            i=i+1;
            max_droite=max_droite+1;
        }
        else if(strcmp(map[posx_bombe+i][posy_bombe].type,"bombe_amorcee")==0){
            i=portee+1; // la deuxieme bombe ira forcement plus loin que la première
            max_droite=max_droite+1;
        }
        else{
            i=i+1;
            max_droite=max_droite+1;
        }
    }
        //regarde l'ouest
    i=1;
    while(i<=portee){
        if(strcmp(map[posx_bombe-i][posy_bombe].type,"mur")==0){
            i=portee+1;
        }
        else if(strcmp(map[posx_bombe-i][posy_bombe].type,"bloc")==0){
            i=portee+1;
            max_gauche=max_gauche+1;
        }
        else if(strcmp(map[posx_bombe-i][posy_bombe].type,"bonus")==0){
            i=i+1;
            max_gauche=max_gauche+1;
        }
        else if(strcmp(map[posx_bombe-i][posy_bombe].type,"joueur1")==0){
            i=i+1;
            max_gauche=max_gauche+1;
        }
        else if(strcmp(map[posx_bombe-i][posy_bombe].type,"joueur2")==0){
            i=i+1;
            max_gauche=max_gauche+1;
        }
        else if(strcmp(map[posx_bombe-i][posy_bombe].type,"bombe_amorcee")==0){
            i=portee+1;
            max_gauche=max_gauche+1;
        }
        else{
            i=i+1;
            max_gauche=max_gauche+1;
        }
    }

        //regarde le nord
    i=1;
    while(i<=portee){
        if(strcmp(map[posx_bombe][posy_bombe+i].type,"mur")==0){
            i=portee+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe+i].type,"bloc")==0){
            i=portee+1;
            max_haut=max_haut+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe+i].type,"bonus")==0){
            i=i+1;
            max_haut=max_haut+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe+i].type,"joueur1")==0){
            i=i+1;
            max_haut=max_haut+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe+i].type,"joueur2")==0){
            i=i+1;
            max_haut=max_haut+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe+i].type,"bombe_amorcee")==0){
            i=portee+1;
            max_haut=max_haut+1;
        }
        else{
            i=i+1;
            max_haut=max_haut+1;
        }
    }

        //regarde le sud
    i=1;
    while(i<=portee){
        if(strcmp(map[posx_bombe][posy_bombe-i].type,"mur")==0){
            i=portee+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe-i].type,"bloc")==0){
            i=portee+1;
            max_bas=max_bas+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe-i].type,"bonus")==0){
            i=i+1;
            max_bas=max_bas+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe-i].type,"joueur1")==0){
            i=i+1;
            max_bas=max_bas+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe-i].type,"joueur2")==0){
            i=i+1;
            max_bas=max_bas+1;
        }
        else if(strcmp(map[posx_bombe][posy_bombe-i].type,"bombe_amorcee")==0){
            i=portee+1;
            max_bas=max_bas+1;
        }
        else{
            i=i+1;
            max_bas=max_bas+1;

        }
    }
    
    affichage_explosion(CASE,max_haut,max_bas,max_droite,max_gauche,renderer);

}
