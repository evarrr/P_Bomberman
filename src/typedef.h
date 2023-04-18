/*Definition de la zone de jeu*/
typedef struct case{
    int posx;
    int posy;
    char* type;
} case_t;


/*definition du joueur*/
typedef struct bonusjoueur{
    int roller;
    int bouclier;
    int saut;

}bonus_joueur_t;

typedef struct bombe{
    int nbbombe3case;
    int nbbombeligne;
}nb_bombe_t;

typedef struct joueur{
    int numjoueur;
    int posx;
    int posy;
    int vie;
    nb_bombe_t arsenal;
    bonus_joueur_t bonus;
}joueur_t;