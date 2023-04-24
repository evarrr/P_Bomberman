#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include "case.h"
#include "typedef.h"
#include "action.h"

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


                case SDL_KEYDOWN:           /*l'action s'effectuera quand on appuie sur la touche pas quand on la relache*/
                    switch(event.key.keysym.sym){

                        //deplacement du joueur1
                            case SDLK_UP:
                                //fais le deplacement vers le haut
                                deplacementJ1(&joueur1,HAUT);                      
                                continue;           /*ne fait pas un break car sinon sort tres  vite*/
                            
                                                
                            case SDLK_DOWN:
                                // fait le deplacement vers le bas
                                deplacementJ1(&joueur1,BAS);
                                continue;
                            
                            case SDLK_RIGHT:
                                // fait le deplacement vers la droite
                                deplacementJ1(&joueur1,DROITE);
                                continue;
                            
                            case SDLK_LEFT:
                                //fait le deplacement vers la gauche
                                deplacementJ1(&joueur1,GAUCHE);
                                continue;

                        


                        //deplacement du joueur2
                            case SDLK_z:
                                //fais le deplacement vers le haut
                                deplacementJ2(&joueur2,HAUT);                      
                                break;           /*ne fait pas un break car sinon sort tres  vite*/
                            
                                                
                            case SDLK_s:
                                // fait le deplacement vers le bas
                                deplacementJ2(&joueur2,BAS);
                                continue;
                            
                            case SDLK_d:
                                // fait le deplacement vers la droite
                                deplacementJ2(&joueur2,DROITE);
                                continue;
                            
                            case SDLK_q:
                                //fait le deplacement vers la gauche
                                deplacementJ2(&joueur2,GAUCHE);
                                continue;

                            

                            //Cas par defaut
                            default:
                                break;
                    }
                    
                default:
                    break;       
            }
        }
   } 



                
    
   

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
  
