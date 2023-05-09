#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"




void deplacementJ1(map_t* map, joueur_t* joueur1,int direction){
    
    //Le joueur1 va se deplacer en utilisant les fleches du clavier
    switch (direction){
        case HAUT:
            if (strcmp(map[joueur1->posy -1][joueur1->posx]->type,"mur")==0){
                break;
            }
            joueur1->posy=joueur1->posy-1;
        
        case BAS:
            if (strcmp(map[joueur1->posy +1][joueur1->posx]->type,"mur")==0){
                break;
            }
            joueur1->posy=joueur1->posy +1;

        case GAUCHE:
            if (strcmp(map[joueur1->posy][joueur1->posx-1]->type,"mur")==0){
                break;
            }
            joueur1->posx=joueur1->posx -1;

        case DROITE:
            if (strcmp(map[joueur1->posy -1][joueur1->posx]->type,"mur")==0){
                break;
            }
            joueur1 ->posx=joueur1->posx +1;
    }
};


void deplacementJ2(map_t* map,joueur_t* joueur2,int direction){
    
    //Le joueur2 va se deplacer en utilisant les touches q,s,d,z
    switch (direction){
        case HAUT:
            if (strcmp(map[joueur2->posy -1][joueur2->posx]->type,"mur")==0){
                break;
            }
            joueur2->posy=joueur2->posy-1;
        
        case BAS:
            if (strcmp(map[joueur2->posy +1][joueur2->posx]->type,"mur")==0){
                break;
            }
            joueur2->posy=joueur2->posy +1;

        case GAUCHE:
            if (strcmp(map[joueur2->posy][joueur2->posx-1]->type,"mur")==0){
                break;
            }
            joueur2->posx=joueur2->posx -1;

        case DROITE:
            if (strcmp(map[joueur2->posy -1][joueur2->posx]->type,"mur")==0){
                break;
            }
            joueur2 ->posx=joueur2->posx +1;
    }
};