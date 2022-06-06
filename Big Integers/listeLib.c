#include "listeLib.h"

#ifndef stdio_h
#include <stdio.h>
#endif
//---------------------------------------
#ifndef stdlib_h
#include <stdlib.h>
#endif

/**
 * @brief Fonction qui permet d'ajouter un élément en tête de liste
 * 
 * @param element   L'élément que nous voulons ajouter
 * @param reste     La liste dans laquelle nous voulons ajouter l'élément
 * @return Liste    Une liste dont la tête est "element" et la queue "reste"
 */
Liste CreerListe(int element, Liste reste){
    Liste L = malloc(sizeof(Liste));
    L->valeur=element;
    L->suivant=reste;
    return L;
}

//Retourner la tete de la liste (premier élément) : 
/**
 * @brief Fonction qui donne le premier élément d'une liste (la tête)
 * 
 * @param L     La liste dont on veut avoir la tête
 * @return int  Le premier élément (tête)
 */
int tete(Liste L){
    return (L->valeur);
}

/**
 * @brief Fonction qui donne une liste privée de sa tête (sans son premier élément)
 * 
 * @param L         La liste dont on veut récupérer la queue
 * @return Liste    La liste sans le premier élément
 */
Liste queue(Liste L){
    return (L->suivant);
}

/**
 * @brief Fonction qui vérifie si une liste est vide
 * 
 * @param L     Une liste
 * @return int  1=vide | 0=non vide
 */
int estVide(Liste L){
    if (L==NULL)
    {
        return 1;
    }else{
        return 0;
    }
}