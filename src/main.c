#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "case.h"
#include "typedef.h"

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

void SDL_ExitWIthError(const char* message);


int main(int argc, char*argv[]){
    int taille=15;
    SDL_Window* window = NULL;
    SDL_Renderer *renderer=NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWIthError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,0,&window,&renderer)!=0)
        SDL_ExitWIthError("Impossible de creer la fenêtre et le rendu");
    map_t map;
    joueur_t joueur1;
    joueur1.vie=3;
    joueur1.numjoueur=1;
    joueur_t joueur2;
    joueur2.vie=3;
    joueur2.numjoueur=2;
    init_mur(taille,map,window,renderer);
    init_bloc_0(taille,map,window,renderer); 
    init_joueur(map,&joueur1,&joueur2);
    affichage_joueur_1(map,joueur1,window,renderer);
    SDL_RenderPresent(renderer);
    /*************************************************************/
    
    SDL_bool program_launched = SDL_TRUE;

   while(program_launched){
    SDL_Event event;

        while(SDL_PollEvent(&event)){
            switch(event.type){
                case SDL_QUIT:
                    program_launched = SDL_FALSE;
                    break;
                default:
                    break;    
            }
        }
   } 
    /*******************************************************************/   
    //Initialisation des murs de la map
    
   /*******************************************************************/
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return EXIT_SUCCESS;

}

 void SDL_ExitWIthError(const char * message){
    SDL_Log("ERREUR: %s > %s\n", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
 }
  
