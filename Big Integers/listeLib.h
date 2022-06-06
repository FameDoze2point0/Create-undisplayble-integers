struct cellule{
    int valeur;
    struct cellule* suivant;
};
typedef struct cellule* Liste;

Liste CreerListe(int,Liste);

int tete(Liste);

Liste queue(Liste);

int estVide(Liste);
