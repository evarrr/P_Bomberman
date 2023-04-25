#ifndef CASE_H
#define CASE_H

#include "typedef.h"
#include "init_bloc_liste.h"
//fonctions de modif de map

void init_mur(int taille,map_t map,SDL_Window* window,SDL_Renderer* renderer);

void init_bloc(int taille,case_t* map);

void init_bonus(int taille,case_t* map);

void explosion(case_t* CASE,case_t* map);

void poser_bombe(case_t* CASE,joueur_t* joueur);

void ramassage(case_t* CASE,case_t* map,joueur_t* joueur);

//fonctions joueur

void deplacement(joueur_t* joueur);

#endif