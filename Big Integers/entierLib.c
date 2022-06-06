#include "listeLib.h"

//---------------------------------------
#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif
//---------------------------------------
#ifndef stdlib_h
#define stdlib_h
#include <stdlib.h>
#endif
//---------------------------------------



/**
 * @brief Fonction qui récupère une saisi sous forme d'une chaine de caractère(un grand entier) et qui transforme cette saisi en une liste
 * 
 * @return Liste Une liste correspondant à un grand entier
 */
Liste CreerEntier(){
    Liste rep=NULL,cursor=NULL;
    char saisi[200];
    int i=0;

    printf("Entrer un nombre\n-->");
    scanf("%s",saisi);
    //taille maximale d'un entier actuellement 199 (200-1 car on a \0 à la fin de la chaine). Peut être modifié selon le besoin
    //cursor permet de garder le dernier élément ajouter (juste avant le NULL) pour ne pas avoir à reparcourir toute la liste lors de l'ajout d'un élément.
    //Liste de caractère, toujours en int mais correspond au code ASCII
    while(saisi[i]!='\0' && i<199){
           
        if(rep==NULL){

            rep=CreerListe(saisi[i],rep);
            cursor=rep;
        }else{

            cursor->suivant=CreerListe(saisi[i], NULL);
            cursor=queue(cursor);
        }
        i++;
    }
    return rep;
}

/**
 * @brief Fonction permettant d'afficher un grand entier, caractère par caractère (cellule par cellule) jusqu'à NULL
 * 
 * @param L La liste que nous voulons afficher
 */
void AfficherEntier(Liste L){

    if(L!=NULL){

        while(L!=NULL){

            printf("%c",tete(L));
            L=L->suivant;
        }
    }
    printf("\n");
}

//Fonction renvoyant la longueur de la liste, cela nous permet de savoir le nombre de chiffre construisant le nombre
/**
 * @brief Fonction permettant de calculer la taille d'une liste (le nombre de cellule)
 * 
 * @param L     Une liste
 * @return int  La taille de la liste (nombre de cellule)
 */
int IntegerSize(Liste L){

    int x=0;
    while(L!=NULL){

        x++;
        L=L->suivant;
    }
    return x;
}

/**
 * @brief Fonction qui compare 2 listes (2 grands entiers)
 * 
 * @param L1    Première liste
 * @param L2    Deuxième liste
 * @return int  L1>L2 donne 1 | L1 < L2 donne 0 | L1 == L2 donne 2
 */
int compare(Liste L1, Liste L2){

    int rep=2;
    //On vérifie dans un premier temps la taille des deux listes, on aurait pu mettre le résultat dans 2 variables pour ne pas avoir à faire 2 fois les appels des fonctions
    //Si la taille est la même on va comparer caractère par caractère s'ils ne sont pas égaux alors on renvoie 1 ou 0 sinon on passe au caractère suivant (si L1 ou L2 NULL c'est qu'ils sont égaux donc renvoie 2)
    if (IntegerSize(L1)>IntegerSize(L2)){

        rep=1;
    }else{

        if (IntegerSize(L1)<IntegerSize(L2)){

            rep=0;
        }else{
            
            while (L1!=NULL && L2!=NULL){

                if (L1->valeur > L2->valeur){

                    rep=1;
                    break;
                }else{

                    if (L1->valeur < L2->valeur){

                        rep=0;
                        break;
                    }
                }
                L1=L1->suivant;
                L2=L2->suivant;
            }
        }  
    }
    return rep;
}