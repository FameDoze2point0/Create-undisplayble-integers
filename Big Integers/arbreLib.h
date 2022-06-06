#define arbreLib_h

#ifndef entierLib_h
#define entierLib_h
#include "entierLib.h"
#endif

#ifndef listeLib_h
#define listeLib_h
#include "listeLib.h"
#endif

struct arbre{
    Liste valeur;
    struct arbre* SAG;
    struct arbre* SAD;
};
typedef struct arbre *Arbre;

Arbre RotaG(Arbre);
Arbre RotaD(Arbre);
Arbre RotaGD(Arbre);
Arbre RotaDG(Arbre);

int max(int,int);

int hauteurArbre(Arbre);

int Desequilibre(Arbre);

Arbre requilibre(Arbre A);

Arbre CreerArbre(Liste,Arbre*);

void ParcoursArbreInf(Arbre);

void ParcoursArbrePre(Arbre);

void ParcoursArbrePost(Arbre);

int RechercheArbre(Arbre,Liste);

Liste EntierMini(Arbre A);

Liste EntierMax(Arbre A);