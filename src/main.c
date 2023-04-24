#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

#define WINDOW_WIDTH 1280
#define WINDOW_HEIGHT 720

void SDL_ExitWIthError(const char* message);


int main(int argc, char*argv[]){

    SDL_Window* window = NULL;
    SDL_Renderer *renderer=NULL;

    //Lancement SDL
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
        SDL_ExitWIthError("Initialisation SDL");

    //Création fenêtre + rendu
    if(SDL_CreateWindowAndRenderer(WINDOW_WIDTH,WINDOW_HEIGHT,0,&window,&renderer)!=0)
        SDL_ExitWIthError("Impossible de creer la fenêtre et le rendu");

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
  
