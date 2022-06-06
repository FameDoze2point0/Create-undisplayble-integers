#ifndef entierLib_h
#define entierLib_h
#include "entierLib.h"
#endif

#ifndef listeLib_h
#define listeLib_h
#include "listeLib.h"
#endif

int CalculCle(Liste);

int CalculIndice(Liste,int);

int CalculeInd2(Liste L,int taille);

void InsertionTable(int id,Liste L, Liste Table[],int taille, long long int * nbCollision);

int ChercheHachage(int id,Liste Table[],Liste element,int taille);

void ParcoursHachage(int,Liste *);
