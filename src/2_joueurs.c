#include <stdlib.h>
#include <stdio.h>
#include <SDL_image.h>

void affichage_joueur_1(map_t map,joueur_t joueur1,SDL_Renderer* renderer)
{
    if(SDL_SetRenderDrawColor(renderer,100,100,255,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }

    SDL_Rect position1, positionJoueur1;
    SDL_Rect position2, positionJoueur2;

    SDL_Surface* perso1=IMG_load("perso_1.png");
    SDL_Surface* perso2=perso2=IMG_load("perso_2.png");


    positionJoueur1.x=joueur1.posx;
    positionJoueur1.y=joueur1.posy;
    map[positionJoueur1.x][positionJoueur1.y]="joueur1"

    positionJoueur2.x=joueur1.posx;
    positionJoueur2.y=joueur2.posy
    map[positionJoueur2.x][positionJoueur2.y]="joueur2"


    position1.x=positionJoueur1.x;
    position1.y=positionJoueur1.y;
    SDL_BlitSurface(perso1,NULL,renderer,&position1);

    position2.x=positionJoueur2.x*42;           //42 correspond àla taille d'un bloc comme ca le perso se déplace pas pixel par pixel mais bloc par bloc
    position2.y=positionJoueur2.y*42;
    SDL_BlitSurface(perso2,NULL,renderer,&position2);  

    SDL_Flip(renderer);
    
    SDL_RenderPresent(renderer);
    SDL_Delay(200);

    SDL_EnableKeyRepear(0,0);

    //Libération de la mémoire dédiée aux images

    SDL_FreeSurface(perso1);
    SDL_FreeSurface(perso2);
}