#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"




void deplacementJ1(joueur_t* joueur1,int direction){
    
    //Le joueur1 va se deplacer en utilisant les fleches du clavier
    switch (direction){
        case HAUT:
            joueur1->posy=joueur1->posy-1;
        
        case BAS:
            joueur1->posy=joueur1->posy +1;

        case GAUCHE:
            joueur1->posx=joueur1->posx -1;

        case DROITE:
            joueur1 ->posx=joueur1->posx +1;
    }
};


void deplacementJ2(case_t* map,joueur_t* joueur2,int direction){
    
    //Le joueur2 va se deplacer en utilisant les touches q,s,d,z
    switch (direction){
        case HAUT:
            joueur2->posy=joueur2->posy-1;
        
        case BAS:
            joueur2->posy=joueur2->posy +1;

        case GAUCHE:
            joueur2->posx=joueur2->posx -1;

        case DROITE:
            joueur2 ->posx=joueur2->posx +1;
    }
};