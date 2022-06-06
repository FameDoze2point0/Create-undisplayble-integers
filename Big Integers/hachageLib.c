#include "hachageLib.h"


#ifndef stdlib_h
#include <stdlib.h>
#endif

#ifndef stdio_h
#include <stdio.h>
#endif

#ifndef math_h
#include <math.h>
#endif

/**
 * @brief Fonction permettant de calculer la clé à partir d'un grand entier / une liste
 * 
 * @param L     Un grand entier
 * @return int  La clé
 */
int CalculCle(Liste L){
    int cle=0;
    int i=1;
    while (L!=NULL){

        /*Exemple : avec l'entier "1485"
        1*1 + 2*4 + 3*8 + 4*5 = 53 (la clé)
        */
        cle=cle + (L->valeur-'0')*i;
        L=L->suivant;
        i++;
    }
    return cle;
}

/**
 * @brief Fonction calculant l'indice d'un grand entier dans une table de hachage (méthode multiplication)
 * 
 * @param L         Un grand entier
 * @param taille    Taille de la table de hachage
 * @return int      L'indice dans la table de hachage
 */
int CalculIndice(Liste L,int taille){
    int cle=CalculCle(L); // on calcule d'abord la clé
    int indice=0;
    double teta=(sqrt(5)-1)/2, tmp;

    tmp=(int)(cle*teta); // on récupère la partie entière de cle*teta
    indice=((cle*teta)-tmp)*taille; // on calcule l'indice en récupérant la partie décimal de cle*teta puis on multiplie à la taille
    return indice;
}

/**
 * @brief Fonction calculant l'indice d'un grand entier dans une table de hachage (méthode division)
 * 
 * @param L         Un grand entier
 * @param taille    Taille de la table de hachage
 * @return int      L'indice dans la table de hachage
 */
int CalculeInd2(Liste L,int taille){

	long hashCle=CalculCle(L); // on calcule d'abord la clé
	int ind=hashCle%taille; // On fait le mode de la clé par la taille ce qui nous donne l'indice dans la table de hachage
	return ind;
}

/**
 * @brief Fonction permettant d'insérer un élément dans une table de hachage
 * 
 * @param id        ID donnant la méthode (multiplication ou division). 1=division sinon multiplication
 * @param L         Le grand entier que nous voulons ajouter à notre table de hachage
 * @param Table     La table de hachage
 * @param taille    La taille de la table de hachage
 */
void InsertionTable(int id,Liste L, Liste Table[],int taille,long long int * nbCollision){
    int indice,NewIndice, i=1;
    if (id==1){

        indice=CalculeInd2(L,taille);
    }else{

        indice=CalculIndice(L,taille);
    }
    
    //Si la case est égal à NULL on met l'entier dedans sinon nous allons parcourir les cases une à une jusqu'au moment où nous aurons une case vide
    if (Table[indice]==NULL){

        Table[indice]=L;
    }else{
        (*nbCollision)++;
        NewIndice=indice;
        while (Table[NewIndice]!=NULL){

            NewIndice=(indice+i)%taille;
            (*nbCollision)++;
            i++;
        }
        Table[NewIndice]=L;
    }
}

/**
 * @brief Fonction de recherche dans une table de hachage
 * 
 * @param id        ID donnant la méthode (multiplication ou division). 1=division sinon multiplication
 * @param Table     La table de hachage
 * @param element   L'élément que nous voulons rechercher
 * @param taille    La taille de la table de hachage
 * @return int      -1 si l'élément n'a pas été retrouvé sinon le nombre de case parcourue
 */
int ChercheHachage(int id,Liste Table[],Liste element,int taille){
    int trouve=1,indice;
    if (id==1){

        indice=CalculeInd2(element,taille);
    }else{

        indice=CalculIndice(element,taille);
    }
    int j=1,newIndice=indice;

    while (compare(Table[newIndice],element)!=2 && Table[newIndice]!=NULL && (j<taille-1)){

        newIndice= (indice + j)%taille; 
        j++;
        trouve++;
    }
    if (compare(Table[newIndice],element)!=2){

        trouve=-1;
    }
    return trouve;
}

/**
 * @brief Fonction permettant de parcourir une table de hachage en affichant les grands entier avec leur indice
 * 
 * @param taille    Taille de la table de hachage
 * @param Table     La table de hachage
 */
void ParcoursHachage(int taille, Liste Table[]){
    for (int i = 0; i < taille; i++){

        if (Table[i]==NULL){

            printf("%d : NULL\n",i);
        }else{

            printf("%d : ",i);
            AfficherEntier(Table[i]);
        }
    }
}