#define chargement_h

#ifndef arbreLib_h
#define arbreLib_h
#include "arbreLib.h"
#endif

#ifndef hachage_h
#define hachage_h
#include "hachageLib.h"
#endif

#ifndef entierLib_h
#define entierLib_h
#include "entierLib.h"
#endif

#ifndef listeLib_h
#define listeLib_h
#include "listeLib.h"
#endif



int ChargementEntier(Arbre * A,Liste TableHachageDiv[],Liste TableHachageMul[],int tailleTable, int nbEntier,long long int * nbCollisionDiv,long long int * nbCollisionMul);

void deleteTable(Liste ** Table);

void deleteEntier(Liste * L);

void deleteArbre(Arbre * A);