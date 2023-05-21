#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "typedef.h"




void deplacementJ1(map_t map, joueur_t* joueur1,int direction){
    
    int taille = 20;//taille en pixels du joueur

    int xgauche=joueur1->posx-7;
    int xmilieu=xgauche+taille/2;
    int xdroite=xgauche+taille;
    int yhaut=joueur1->posy-7;
    int ymilieu=yhaut+taille/2;
    int ybas=yhaut+taille;

    int x_entier_gauche=xgauche/42;
    int x_entier_milieu=xmilieu/42;
    int x_entier_droite=xdroite/42;
    int y_entier_haut=yhaut/42;
    int y_entier_milieu=ymilieu/42;
    int y_entier_bas=ybas/42;
    // printf("%d\n",x_entier);
    // printf("%d\n",y_entier); 
    int future_posx;
    int future_posy;
    int future_pos_matrice;
    char* contenu_future_pos_1;
    char* contenu_future_pos_2;
    //Le joueur1 va se deplacer en utilisant les fleches du clavier
    switch (direction){
        case GAUCHE:
            // printf("gauche\n");
            future_posx=xgauche-2;
            future_pos_matrice=future_posx/42;
            contenu_future_pos_1=map[future_pos_matrice][y_entier_haut].type;
            contenu_future_pos_2=map[future_pos_matrice][y_entier_bas].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }     
            joueur1->posx=(joueur1->posx)-2;
            if(x_entier_milieu!=(xmilieu-2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[future_pos_matrice][y_entier_milieu].type="joueur1";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;
        
        case DROITE:
            // printf("droite\n");
            future_posx=xdroite+2;
            future_pos_matrice=future_posx/42;
            contenu_future_pos_1=map[future_pos_matrice][y_entier_haut].type;
            contenu_future_pos_2=map[future_pos_matrice][y_entier_bas].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            joueur1->posx=(joueur1->posx) +2;
            if(x_entier_milieu!=(xmilieu+2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[future_pos_matrice][y_entier_milieu].type="joueur1";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;

        case BAS:
            future_posy=ybas+2;
            future_pos_matrice=future_posy/42;
            contenu_future_pos_1=map[x_entier_droite][future_pos_matrice].type;
            contenu_future_pos_2=map[x_entier_gauche][future_pos_matrice].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            joueur1 ->posy=joueur1->posy +2;
            if(y_entier_milieu!=(ymilieu+2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[x_entier_milieu][future_pos_matrice].type="joueur1";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;

        case HAUT:
            future_posy=yhaut-2;
            future_pos_matrice=future_posy/42;
            contenu_future_pos_1=map[x_entier_droite][future_pos_matrice].type;
            contenu_future_pos_2=map[x_entier_gauche][future_pos_matrice].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            joueur1->posy=joueur1->posy -2;
            if(y_entier_milieu!=(ymilieu-2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[x_entier_milieu][future_pos_matrice].type="joueur1";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;


    }
};


void deplacementJ2(map_t map,joueur_t* joueur2,int direction){
    
    //Le joueur2 va se deplacer en utilisant les touches q,s,d,z
    int taille = 20;//taille en pixels du joueur

    int xgauche=joueur2->posx-7;
    int xmilieu=xgauche+taille/2;
    int xdroite=xgauche+taille;
    int yhaut=joueur2->posy-7;
    int ymilieu=yhaut+taille/2;
    int ybas=yhaut+taille;

    int x_entier_gauche=xgauche/42;
    int x_entier_milieu=xmilieu/42;
    int x_entier_droite=xdroite/42;;
    int y_entier_haut=yhaut/42;
    int y_entier_milieu=ymilieu/42;
    int y_entier_bas=ybas/42;
    // printf("%d\n",x_entier);
    // printf("%d\n",y_entier); 
    int future_posx;
    int future_posy;
    int future_pos_matrice;
    char* contenu_future_pos_1;
    char* contenu_future_pos_2;
    switch (direction){
        case GAUCHE:
            // printf("gauche\n");
            future_posx=xgauche-2;
            future_pos_matrice=future_posx/42;
            contenu_future_pos_1=map[future_pos_matrice][y_entier_haut].type;
            contenu_future_pos_2=map[future_pos_matrice][y_entier_bas].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }     
            joueur2->posx=(joueur2->posx)-2;
            if(x_entier_milieu!=(xmilieu-2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[future_pos_matrice][y_entier_milieu].type="joueur2";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;
            
        
        case DROITE:
            // printf("droite\n");
            future_posx=xdroite+2;
            future_pos_matrice=future_posx/42;
            contenu_future_pos_1=map[future_pos_matrice][y_entier_haut].type;
            contenu_future_pos_2=map[future_pos_matrice][y_entier_bas].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            
            joueur2->posx=(joueur2->posx) +2;
            if(x_entier_milieu!=(xmilieu+2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[future_pos_matrice][y_entier_milieu].type="joueur2";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;

        case BAS:
            future_posy=ybas+2;
            future_pos_matrice=future_posy/42;
            contenu_future_pos_1=map[x_entier_droite][future_pos_matrice].type;
            contenu_future_pos_2=map[x_entier_gauche][future_pos_matrice].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            joueur2 ->posy=joueur2->posy +2;
            if(y_entier_milieu!=(ymilieu+2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[x_entier_milieu][future_pos_matrice].type="joueur2";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;

        case HAUT:
            future_posy=yhaut-2;
            future_pos_matrice=future_posy/42;
            contenu_future_pos_1=map[x_entier_droite][future_pos_matrice].type;
            contenu_future_pos_2=map[x_entier_gauche][future_pos_matrice].type;
            if (strcmp(contenu_future_pos_1,"mur")==0||strcmp(contenu_future_pos_2,"mur")==0){
                printf("mur\n");
                break;
            }
            if (strcmp(contenu_future_pos_1,"bloc")==0||strcmp(contenu_future_pos_2,"bloc")==0){
                printf("bloc\n");
                break;
            }           
            joueur2->posy=joueur2->posy -2;
            if(y_entier_milieu!=(ymilieu-2)/42)//on change le joueur de place dans la matrice si au moins la moitié de son "sprite" change de case
            {
                map[x_entier_milieu][future_pos_matrice].type="joueur2";
                map[x_entier_milieu][y_entier_milieu].type="vide";
            }
            break;


    }
};