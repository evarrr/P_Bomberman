#include <stdlib.h>
#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "typedef.h"

void affichage_joueur(map_t map,joueur_t joueur1,joueur_t joueur2,SDL_Renderer* renderer)
{
    if(SDL_SetRenderDrawColor(renderer,100,100,255,SDL_ALPHA_OPAQUE)!=0)
    {
        SDL_Quit();
    }

    // SDL_Rect position1, positionJoueur1;
    // SDL_Rect position2, positionJoueur2;

    SDL_Surface* perso1=IMG_Load("perso_1.png");
    // SDL_Surface* perso2=IMG_Load("perso_2.png");

    if ( perso1 )
    {
        SDL_Texture* pTexture = SDL_CreateTextureFromSurface(renderer,perso1); // Préparation du sprite
        if ( pTexture )
        {
            SDL_Rect dest = { 640/2 - perso1->w/2,480/2 - perso1->h/2, perso1->w, perso1->h};
            SDL_RenderCopy(renderer,pTexture,NULL,&dest); // Copie du sprite grâce au SDL_Renderer
            
            SDL_RenderPresent(renderer); // Affichage
            SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */
            
            SDL_DestroyTexture(pTexture); // Libération de la mémoire associée à la texture
        }
        else
        {
            fprintf(stdout,"Échec de création de la texture (%s)\n",SDL_GetError());
        }
        
        SDL_FreeSurface(perso1); // Libération de la ressource occupée par le sprite
    }
    else
    {
        fprintf(stdout,"Échec de chargement du sprite (%s)\n",SDL_GetError());
    }

    // positionJoueur1.x=joueur1.posx;
    // positionJoueur1.y=joueur1.posy;
    // map[positionJoueur1.x][positionJoueur1.y].type="joueur1";

    // positionJoueur2.x=joueur1.posx;
    // positionJoueur2.y=joueur2.posy;
    // map[positionJoueur2.x][positionJoueur2.y].type="joueur2";


    // position1.x=positionJoueur1.x;
    // position1.y=positionJoueur1.y;
    // SDL_BlitSurface(perso1,NULL,renderer,&position1);

    // position2.x=positionJoueur2.x*42;           //42 correspond àla taille d'un bloc comme ca le perso se déplace pas pixel par pixel mais bloc par bloc
    // position2.y=positionJoueur2.y*42;
    // SDL_BlitSurface(perso2,NULL,renderer,&position2);  

    // SDL_Flip(renderer);
    
    // SDL_RenderPresent(renderer);
    // SDL_Delay(200);

    // SDL_EnableKeyRepear(0,0);

    //Libération de la mémoire dédiée aux images

    SDL_FreeSurface(perso1);
    // SDL_FreeSurface(perso2);
}