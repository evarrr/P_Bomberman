#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"




void deplacementJ1(map_t map, joueur_t* joueur1,int direction){
    

    int x_entier=(joueur1->posx-17)/42;
    int y_entier=(joueur1->posy-17)/42;
    printf("%d\n",x_entier);
    printf("%d\n",y_entier); 
    //Le joueur1 va se deplacer en utilisant les fleches du clavier
    switch (direction){
        case GAUCHE:
            if (strcmp(map[x_entier -1][y_entier].type,"mur")==0){
                break;
            }
            joueur1->posx=joueur1->posx-1;
        
        case DROITE:
            printf("%s\n",map[x_entier+1][y_entier].type);
            if (strcmp(map[x_entier +1][y_entier].type,"mur")==0){
                break;
                
            }
            printf("test2\n");
            joueur1->posx=(joueur1->posx) +1;

        case HAUT:
            if (strcmp(map[x_entier][y_entier-1].type,"mur")==0){
                break;
            }
            joueur1->posy=joueur1->posy -1;

        case BAS:
            if (strcmp(map[x_entier][y_entier+1].type,"mur")==0){
                break;
            }
            joueur1 ->posy=joueur1->posy +1;
    }
    printf("%d\n",joueur1->posy);
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