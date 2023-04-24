#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"


void deplacement(case_t* case,case_t* map,joueur_t* joueur,int direction){
    
    switch (direction){
        case HAUT:
            joueur->posy=joueur->posy-1;
        
        case BAS:
            joueur->posy=joueur->posy +1;

        case GAUCHE:
            joueur->posx=joueur->posx -1;
        case DROITE:
            joueur ->posx=joueur->posx +1;
    }
}