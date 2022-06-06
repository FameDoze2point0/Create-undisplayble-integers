#include "arbreLib.h"

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
 * @brief Fonction vérifiant si un arbre est vide ou non
 * 
 * @param A     Un arbre
 * @return int  1 si l'arbre est nul | 0 si l'arbre est non nul
 */
int ArbreVide(Arbre A){
    int x=0;
    if (A==NULL){

        x=1;
    }
    return x;
}

/**
 * @brief Fonction nous donnant le sous arbre gauche de A
 * 
 * @param A Un arbre
 * @return Arbre Le sous arbre gauche de A
 */
Arbre g(Arbre A){
    return A->SAG;
}
/**
 * @brief Fonction nous donnant le sous arbre droit de A
 * 
 * @param A Un arbre
 * @return Arbre Le sous arbre droit de A
 */
Arbre d(Arbre A){
    return A->SAD;
}

/**
 * @brief Fonction faisant une rotation gauche d'un arbre
 * 
 * @param A     Un arbre
 * @return Arbre L'arbre après la rotation
 */
Arbre RotaG(Arbre A){
    Arbre tmp=A;
    A=d(A);
    tmp->SAD=g(A);
    A->SAG=tmp;
    return A;
}
/**
 * @brief Fonction faisant une rotation droit d'un arbre
 * 
 * @param A     Un arbre
 * @return Arbre L'arbre après la rotation
 */
Arbre RotaD(Arbre A){
    Arbre tmp=A;
    A=g(A);
    tmp->SAG=d(A);
    A->SAD=tmp;
    return A;
}
/**
 * @brief Fonction faisant une rotation gauche-droit d'un arbre
 * 
 * @param A     Un arbre
 * @return Arbre L'arbre après la rotation
 */
Arbre RotaGD(Arbre A){
    A->SAG=RotaG(g(A));
    A=RotaD(A);
    return A;
}
/**
 * @brief Fonction faisant une rotation gauche-droit d'un arbre
 * 
 * @param A     Un arbre
 * @return Arbre L'arbre après la rotation
 */
Arbre RotaDG(Arbre A){
    A->SAD=RotaD(d(A));
    A=RotaG(A);
    return A;
}

/**
 * @brief Fonction donnant le maximum entre 2 entiers
 * 
 * @param a     Premier entier
 * @param b     Deuxième entier
 * @return int  L'entier le plus grand entre "a" et "b"
 */
int max(int a,int b){
    if (a<b){

        return b;
    }else{

        return a;
    }
}

/**
 * @brief Fonction donnant la hauteur d'un Arbre (nombre maximum de noeud jusqu'au feuille)
 * 
 * @param A     Un arbre
 * @return int  La hauteur de l'arbre A
 */
int hauteurArbre(Arbre A){
    if (ArbreVide(A)){

        return -1;
    }else{

        return 1+max(hauteurArbre(A->SAG),hauteurArbre(A->SAD));
    }
}

/**
 * @brief Fonction donnant le déséquilibre d'un arbre, hauteur du SAG - hauteur du SAD
 * 
 * @param A     Un arbre
 * @return int  Le déséquilibre de A
 */
int Desequilibre(Arbre A){
    int rep=0;
    if (!ArbreVide(A)){

        return (hauteurArbre(A->SAG)-hauteurArbre(A->SAD));
    }
    return rep;
}

/**
 * @brief Fonction vérifiant le desequilibre d'un Arbre et fait les rotations si nécessaire
 * 
 * @param A         Un arbre
 * @return Arbre    Arbre après les potentielles rotations
 */
Arbre requilibre(Arbre A){

    if (Desequilibre(A)==2 || Desequilibre(A)==-2){

        if (Desequilibre(A)==2){

            if (Desequilibre(A)==2 && Desequilibre(A->SAG)>=0){

                A=RotaD(A);
            }else{

                A=RotaGD(A);
            }
        }else{

            if (Desequilibre(A)==-2 && Desequilibre(A->SAD)<=0){

                A=RotaG(A);
            }else{
                A=RotaDG(A);
            }
        }  
    }
    return A;
}

/**
 * @brief Fonction ajoutant un élément à un arbre 
 * 
 * @param element   L'élément que nous voulons ajouter
 * @param A         L'arbre dans lequel vous voulez ajouter l'élément
 * @return Arbre    L'arbre après l'ajout et rotations si besoin
 */
Arbre CreerArbre(Liste element,Arbre* A){
    Arbre copie=*A;

    if (ArbreVide(copie)){

        copie=malloc(sizeof(Arbre));
        copie->valeur=element;
        copie->SAG=NULL;
        copie->SAD=NULL;
    }else{

        if (compare(element,copie->valeur)>0){

            copie->SAD=CreerArbre(element,&(copie->SAD));
        }else{

            copie->SAG=CreerArbre(element,&(copie->SAG));
        }
    }

    copie=requilibre(copie);
    
    return copie;
}

/**
 * @brief Fonction récursives du parcours d'un arbre (infixe)
 * 
 * @param A L'arbre que nous voulons afficher
 */
void ParcoursArbreInf(Arbre A){
    int rep;
    if(A!=NULL){
        
        ParcoursArbreInf(A->SAG);
        AfficherEntier(A->valeur);
        ParcoursArbreInf(A->SAD);
    }
}

/**
 * @brief Fonction récursives du parcours d'un arbre (prefixe)
 * 
 * @param A L'arbre que nous voulons afficher
 */
void ParcoursArbrePre(Arbre A){
    if(A!=NULL){
        
        AfficherEntier(A->valeur);
        ParcoursArbrePre(A->SAG);
        ParcoursArbrePre(A->SAD);
    }
}

/**
 * @brief Fonction récursives du parcours d'un arbre (postfixe)
 * 
 * @param A L'arbre que nous voulons afficher
 */
void ParcoursArbrePost(Arbre A){
    if(A!=NULL){
        
        ParcoursArbrePost(A->SAG);
        ParcoursArbrePost(A->SAD);
        AfficherEntier(A->valeur);
    }
}

/**
 * @brief Fonction de recherche d'un élément dans un arbre
 * 
 * @param A L'arbre dans lequel nous voulons chercher l'élément
 * @param element  L'élément que nous voulons rechercher
 * @return int  Gestion d'erreur + information sur le nombre de noeud parcouru (-1 si erreur sinon nombre de noeud parcouru)
 */
int RechercheArbre(Arbre A, Liste element){
    int nb=1;
    if (!ArbreVide(A)){

        if (compare(element,A->valeur)==1){

            nb=1+RechercheArbre(d(A),element);
        }else{

            if (compare(element,A->valeur)==0){

                nb=1+RechercheArbre(g(A),element);
            }
        }
    }else{

        nb=-1;
    }

    //nécessaire, si nous avons parcouru plusieurs noeud mais qu'au final on ne trouve pas l'élément nous aurons par exemple 7-1 donc 6, la gestion d'erreur est donc fausse. Mais si nous faisons ça, nous reviendrons à 0 à chaque retour et au dernier nous passons à -1.
    if (nb==0){

        nb=-1;
    }
    return nb;
}

/**
 * @brief Fonction donnant le plus petit des grands entiers d'un arbre
 * 
 * @param A     Un Arbre
 * @return Liste    Le plus petit des grands entiers
 */
Liste EntierMini(Arbre A){
    Liste L=NULL;
    if (A!=NULL)
    {
        while (g(A)!=NULL)
        {
            A=g(A);
        }
        L=A->valeur;
    }
    return L;
}
/**
 * @brief Fonction donnant le plus grand des grands entiers d'un arbre
 * 
 * @param A     Un Arbre
 * @return Liste    Le plus grand des grands entiers
 */
Liste EntierMax(Arbre A){
    Liste L=NULL;
    if (A!=NULL)
    {
        while (d(A)!=NULL)
        {
            A=d(A);
        }
        L=A->valeur;
    }
    return L;
}