#ifndef entierLib_h
#include "entierLib.h"
#endif
//---------------------------------------
#ifndef arbreLib_h
#include "arbreLib.h"
#endif
//---------------------------------------
#ifndef hachage_h
#include "hachageLib.h"
#endif
//---------------------------------------
#ifndef chargement_h
#include "chargement.h"
#endif
//---------------------------------------
#ifndef stdio_h
#include <stdio.h>
#endif
//---------------------------------------
#ifndef stdlib_h
#include <stdlib.h>
#endif
//---------------------------------------
#ifndef time_h
#include <time.h>
#endif

#include <unistd.h>

int main(int argc, char const *argv[])
{
    //Variable des temps / réponses
    int repAVL,repMul,repDiv,sec,info=0;
    clock_t debut, fin;
    double dureeChargement,dureeAVL,dureeMul,dureeDiv,constanteTemps=CLOCKS_PER_SEC;
    //----------------------------------------------------------
    //Variable du menu
    int continu=1,lvlmenu=1,choix;
    //----------------------------------------------------------
    //Variable sur les tables/ arbres
    int nbEntier,tailleTable;
    long long int nbCollisionDiv,nbCollisionMul;
    Arbre Tree=NULL;
    Liste Lrecherche=NULL,mini=NULL,max=NULL;
    Liste * TableHachageDiv=NULL,* TableHachageMul=NULL;
    //----------------------------------------------------------

    system("clear");//on efface ce qui est dans le terminal, purement subjectif pour un rendu plus propre (on le fera plus tard aussi)
    printf("Bienvenue sur le projet 'Les grands entiers' fait par BEN KADOUR Fatima et CARPENTIER Antonin\n\n");

    while (continu){ 
        //pseudo boucle infinie pour que l'utilisateur puisse faire autant d'action qu'il le veut

        if (lvlmenu==1){

            //premier niveau du menu, on peut soit quitter le programme, soit charger des entiers
            printf("Que voulez-vous faire ? (entrez une valeur présente entre crochet)\n\n\t - Quitter le programme\t[0]\n\t - Charger des entier\t[1]\n\nVotre choix : ");

        }else if (lvlmenu == 4 && info==0){

            //deuxième niveau du menu, on peut soit quitter le programme, soit charger des entiers, soit afficher les entiers (via l'AVL), soit afficher les tables de hachages ou encore chercher un élément
            //nous aurons aussi le temps qu'a mis le chargement à s'effectuer, mais aussi le plus petit élément et le plus grand
            printf("Que voulez-vous faire ? (entrez une valeur présente entre crochet)\n\n\t - Quitter le programme\t\t\t[0]\n\t - Charger des entiers\t\t\t[1]\n\t - Afficher l'AVL \t\t\t[2]\n\t - Afficher les tables de hachage \t[3]\n\t - Chercher un élément\t\t\t[4]\n\nVous avez chargé %d éléments\nLa taille des tables de hachage fait %d cases\nLe chargement a mis %lf secondes\nLa table de hachage (division) a eu %lld collisions\nLa table de hachage (multiplication) a eu %lld collisions\n",nbEntier,tailleTable,dureeChargement,nbCollisionDiv,nbCollisionMul);

            printf("\nL'entier le plus petit du chargement : ");
            AfficherEntier(mini);
            printf("L'entier le plus grand du chargement : ");
            AfficherEntier(max);
            printf("\n\nVotre choix : ");

        }else if (lvlmenu == 4 && info==1){

            //Même chose que le deuxième niveau sauf qu'on a des informations après que l'utilisateur ait effectué une recherche d'entier (nous aurons le temps des différentes recherches, le nombre de noeud parcouru et le nombre de case visitée)
            printf("Que voulez-vous faire ? (entrez une valeur présente entre crochet)\n\n\t - Quitter le programme\t\t\t[0]\n\t - Charger des entiers\t\t\t[1]\n\t - Afficher l'AVL \t\t\t[2]\n\t - Afficher les tables de hachage \t[3]\n\t - Chercher un élément\t\t\t[4]\n\nVous avez chargé %d éléments\nLa taille des tables de hachage fait %d cases\nLe chargement a mis %lf secondes\nLa table de hachage (division) a eu %lld collisions\nLa table de hachage (multiplication) a eu %lld collisions\n",nbEntier,tailleTable,dureeChargement,nbCollisionDiv,nbCollisionMul);

            printf("\nL'entier le plus petit du chargement : ");
            AfficherEntier(mini);
            printf("L'entier le plus grand du chargement : ");
            AfficherEntier(max);

            printf("\nElement recherché :");
            AfficherEntier(Lrecherche);
            if (repAVL==-1){

                printf("\n\nL'élément n'a pas été trouvé, la recherche dans un AVL a mis %lf millisecondes.\n",dureeAVL);
            }else{
                printf("\n\nL'élément a été trouvé, la recherche dans un AVL a mis %lf millisecondes.L'élément a été trouvé au bout de %d noeud(s)\n",dureeAVL,repAVL);
            }

            if (repMul!=-1){

                printf("L'élément a été trouvé, la recherche dans une table de hachage (méthode multiplication) a mis %lf millisecondes.L'élément a été trouvé au bout de %d case(s)\n",dureeMul,repMul);
            }else{
                printf("L'élément n'a pas été trouvé, la recherche dans une table de hachage (méthode multiplication) a mis %lf millisecondes.\n",dureeMul);
            }

            if (repDiv!=-1){

                printf("L'élément a été trouvé, la recherche dans une table de hachage (méthode division) a mis %lf millisecondes.L'élément a été trouvé au bout de %d case(s)\n",dureeDiv,repDiv);
            }else{
                printf("L'élément n'a pas été trouvé, la recherche dans une table de hachage (méthode division) a mis %lf millisecondes.\n",dureeDiv);
            }
            printf("\nVotre choix : ");
        }

        scanf("%d",&choix);
        while (choix<0 || choix>lvlmenu){
            //sécurité pour éviter que l'utilisateur puisse rechercher un élément avant même qu'il ait chargé des entiers
            printf("\nVotre choix : ");
            scanf("%d",&choix);
        }

        if (choix==0){
            //L'utilisateur veut quitter le programme
            printf("\nVous avez quitté le programme !\n");
            break;
        }else if (choix==1){
            //L'utilisateur veut charger des entiers, on passe donc au niveau supérieur (lvlmenu=3)
            lvlmenu=4;
            
            printf("\nCombien d'entier voulez-vous charger : ");
            scanf("%d",&nbEntier);

            printf("\nVeuillez choisir la taille des tables de hachages (minimum %d) : ",nbEntier+1);
            scanf("%d",&tailleTable);
            //----------------------------------------------------------
            //sécurité pour les tables de hachage
            while (tailleTable<=nbEntier){
                
                printf("\nVeuillez choisir la taille des tables de hachages (minimum %d) : ",nbEntier+1);
                scanf("%d",&tailleTable);
            }
            deleteTable(&TableHachageDiv);
            deleteTable(&TableHachageMul);
            deleteArbre(&Tree);
            
            //----------------------------------------------------------
            //On alloue un certain nombre de "case" au table de hachage
            TableHachageDiv=(Liste*)malloc(tailleTable*sizeof(Liste));
            TableHachageMul=(Liste*)malloc(tailleTable*sizeof(Liste));
            for (int i = 0; i < tailleTable; i++){
                //on initialise toutes les cases à NULL afin d'éviter tout problème lors d'une potentielle recherche
                TableHachageDiv[i]=NULL;
                TableHachageMul[i]=NULL;
            }

            debut=clock();
            ChargementEntier(&Tree,TableHachageDiv,TableHachageMul,tailleTable,nbEntier,&nbCollisionDiv,&nbCollisionMul);//chargement
            fin=clock();
            dureeChargement=(fin-debut)/constanteTemps; //calcul du temps de chargement
            
            mini=EntierMini(Tree); //on cherche le plus petit élément
            max=EntierMax(Tree); //on cherche le plus grand élément

        }else if (choix == 2){

            //L'utilisateur veut afficher l'AVL, on va lui proposer 3 façons (infixe/prefixe/postfixe)
            printf("\n\nVeuillez choisir le paramètre que vous voulez utiliser\n\t - Parcours infixe \t[1]\n\t - Parcours prefixe \t[2]\n\t - Parcours postfixe \t[3]\n\nVotre choix : ");
            scanf("%d",&choix);
            while (choix !=1 && choix !=2 && choix !=3){

                printf("\nVotre choix : ");
                scanf("%d",&choix);
            }

            printf("\nCombien de temps voulez-vous que l'affichage dure (temps en seconde) : ");
            scanf("%d",&sec);
            while (sec<0){
                //sécurité temps négatif impossible
                printf("\nVeuillez entrer un temps valide : ");
                scanf("%d",&sec);
            }
            
            if (choix==1){

                printf("\nParcours arbre : \n");
                ParcoursArbreInf(Tree);
            
            }else if (choix==2){

                printf("\nParcours arbre : \n");
                ParcoursArbrePre(Tree);
            
            }else{
            
                printf("\nParcours arbre : \n");
                ParcoursArbrePost(Tree);
            }
            sleep(sec);
            
        }else if (choix==3){

            //L'utilisateur veut afficher les tables de hachage
            printf("\nCombien de temps voulez-vous que l'affichage dure (temps en seconde) : ");
            scanf("%d",&sec);
            while (sec<0){
                //sécurité temps négatif impossible
                printf("\nVeuillez entrer un temps valide : ");
                scanf("%d",&sec);
            }

            printf("\nTable hachage (division) : \n");
            ParcoursHachage(tailleTable,TableHachageDiv);

            printf("\nTable hachage (multiplication) : \n");
            ParcoursHachage(tailleTable,TableHachageMul);
            sleep(sec);

        }else if (choix == 4){
            //L'utilisateur veut chercher un élément, on passe au dernier niveau du menu
            info=1;
            printf("\n");
            Lrecherche=CreerEntier(); //on crée l'entier que l'utilisateur veut rechercher

            //-------------------------------------------------------
            debut=clock();
            repAVL=RechercheArbre(Tree,Lrecherche);
            fin=clock();
            dureeAVL=(double)1000*(fin-debut)/constanteTemps;
            //-------------------------------------------------------
            debut=clock();
            repMul=ChercheHachage(2,TableHachageMul,Lrecherche,tailleTable);
            fin=clock();
            dureeMul=1000*(fin-debut)/constanteTemps;
            //-------------------------------------------------------
            debut=clock();
            repDiv=ChercheHachage(1,TableHachageDiv,Lrecherche,tailleTable);
            fin=clock();
            dureeDiv=1000*(fin-debut)/constanteTemps;
    
        }    
        system("clear");
    }

    deleteTable(&TableHachageDiv);
    deleteTable(&TableHachageMul);
    deleteArbre(&Tree);
    printf("\n\n");

    return 0;
}
