#ifndef CASE_H
#define CASE_H

#include "typedef.h"

//fonctions de modif de map

void init_mur(int taille,map_t map,SDL_Renderer* renderer);

void init_bloc_0(int taille,map_t map,SDL_Renderer* renderer);

void init_joueur(map_t map,joueur_t *joueur_1, joueur_t* joueur_2); 

void init_bonus(int taille,case_t* map);

void explosion(case_t* CASE,map_t map,SDL_Renderer* renderer,joueur_t* joueur1,joueur_t* joueur2);

void poser_bombe(case_t* CASE,joueur_t* joueur);

#endif