#ifndef AFFICHAGE
#define AFFICHAGE

#include "typedef.h"

int max(int a,int b);

void affichage_explosion(case_t* CASE,int max_haut,int max_bas,int max_droite,int max_gauche,SDL_Renderer* renderer);

#endif