#include "chargement.h"

#ifndef stdlib_h
#define stlib_h
#include <stdlib.h>
#endif

#ifndef stdio_h
#define stdio_h
#include <stdio.h>
#endif



/**
 * @brief Fonction qui permet de charger un certain nombre d'entier (que l'utilisateur a choisi) grâce à un fichier et qui crée un arbre (AVL) et 2 tables de hachage au fur et à mesure
 * 
 * @param A     Un arbre
 * @param TableHachageDiv   Table de hachage (avec la méthode des divisions)
 * @param TableHachageMul   Table de hachage (avec la méthode de la multiplication)
 * @param tailleTable       Taille des tables de hachage
 * @param nbEntier          Nombre d'élément à charger dans le fichier
 * @return int              Une erreur si le fichier n'a pas pu être ouvert (1 erreur | 0 pas d'erreur)
 */
int ChargementEntier(Arbre * A,Liste TableHachageDiv[],Liste TableHachageMul[],int tailleTable, int nbEntier,long long int * nbCollisionDiv,long long int * nbCollisionMul){
    FILE * fichier=NULL;
    int error=1,i,x=0;
    char saisi[300];
    Liste lst=NULL,cursor=NULL;
    if ((fichier=fopen("entier.txt","r"))!=NULL)
    {
        while (fscanf(fichier,"%[^\n]\n",saisi)!=EOF && x<nbEntier)
        {
            i=0;
            cursor=NULL;
            lst=NULL;
            while (saisi[i]!='\0')
            {
                if(lst==NULL){

                    lst=CreerListe(saisi[i],lst);
                    cursor=lst;

                }else{

                    cursor->suivant=CreerListe(saisi[i], NULL);
                    cursor=queue(cursor);
                }
                i++;
            }
            *A=CreerArbre(lst,A);
            InsertionTable(1,lst,TableHachageDiv,tailleTable,nbCollisionDiv);
            InsertionTable(2,lst,TableHachageMul,tailleTable,nbCollisionMul);
            x++;
        }
        error=0;
        fclose(fichier);
    }else{
        fprintf(stderr,"[INFO]: Une erreur est survenue : Ouverture du fichier des entiers \n");
    }
    return error;
}

/**
 * @brief Fonction permettant de supprimer une table de hachage
 * 
 * @param Table Une table de hachage
 */
void deleteTable(Liste ** Table){
    //Nous avons Liste ** au lieu de Liste * car nous faisons passer l'adresse du pointeur (&TableDiv) pour pouvoir le libérer
    if (*(Table)!=NULL){
        
        free(*(Table));
        *(Table)=NULL;
    }
}

/**
 * @brief Fonction permettant de supprimer un entier
 * 
 * @param L Un entier
 */
void deleteEntier(Liste * L){
    if (*L!=NULL){

        //nous parcourons jusqu'à arriver à NULL, une fois à NULL, nous allons revenir et donc libérer l'espace au fur et à mesure que l'on remonte  
        deleteEntier(&((*L)->suivant));
        free(*L);
        *L=NULL;
    }
}

/**
 * @brief Fonction permettant de libérer et supprimer un Arbre grâce au parcours postfixe. On libère les entiers aussi au fur et à mesure
 * 
 * @param A  Un arbre
 */
void deleteArbre(Arbre * A){
    if (*A!=NULL){
        //Nous avons Arbre * car nous travaillons directement sur l'adresse de notre arbre, pour que ça ne soit pas une copie
        //On descend dans l'arbre et la libération de la mémoire se fera en remontant dans la récursivité 
        deleteArbre(&((*A)->SAG));
        deleteArbre(&((*A)->SAD));
        deleteEntier(&((*A)->valeur));
        free((*A));
        (*A)=NULL;
    }
}
