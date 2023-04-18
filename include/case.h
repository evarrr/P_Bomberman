#include "typedef.h"
#include "init_bloc_liste.h"
//fonctions de modif de map

void init_mur(int taille,case_t* map);

void init_bloc(int taille,case_t* map);

void init_bonus(int taille,case_t* map);

void explosion(case_t* case,case_t* map);

void poser_bombe(case_t* case,joueur_t* joueur);

void ramassage(case_t* case,case_t* map,joueur_t* joueur);

//fonctions joueur

void deplacement(joueur_t* joueur)