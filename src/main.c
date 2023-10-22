#include <stdio.h>
//#include <stdsrc.h>
#include <time.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "fonctions/fonctions.h"
#include "joueur/joueur.h"
#include "monstre/monstre.h"
#include "objet/objet.h"
#include "sort/sort.h"
#include "fonctions/fonctions.c"
#include "joueur/joueur.c"
#include "objet/objet.c"
#include "monstre/monstre.c"
int main()
{
    srand(time(NULL));    // Initialise le générateur de  nbrmonstres aléatoires avec l'heure actuelle
    int choix;
    afficherMenu();    // On affiche le menu
    //move(5, 15);
    printf("ENTRER VOTRE CHOIX : ");
    scanf(" %d", &choix);
    //getch();
    if(choix == 1){
        // Initialise le joueur
        Joueur joueur;       
        initialiserJoueur(&joueur);

        //afficher la barre de vie
        afficherVie(&joueur);        
        printf("\n");

        // on génère l'arme de l'utilisateur
        Objet objet = genererObjet();

        // on affiche l'objet d'attaque ainsi que la puissance de l'arme
        afficherObjet(&objet,&joueur);        
        printf("attaque \n");

        // DÉFINIR LE nbrmonstre DE MONSTRE
        int nbrmonstre = rand()%10 + 4;
        printf("nombre  de montre : %d \n", nbrmonstre);
        
        //Définir le nbrmonstre d'attaque du joueur
        int nbrAttaqueJoueur = rand()%10 + 4;
        printf("nombre  d'attaque de Sami est : %d \n",nbrAttaqueJoueur);

        // initialiser les monstre
        Monstre *tabMonstre[nbrmonstre];
        printf("le tableau de monstre est créer\n");

        //on enrégistre les monstre dans un tableau
        for (int i = 0; i < nbrmonstre ; i++){
            tabMonstre[i] = malloc(sizeof(Monstre));
            *tabMonstre[i] = genererMonstre(); //*_monstre;
        }
        printf("tout les montre sont générer \n");

        // affichage de chaque monstre
        for (int i = 0; i < nbrmonstre ; i++){
            printf("monstre %d \n", i);
            printf("monstre vie : %d \n", tabMonstre[i]->vie);
            printf("monstre défense : %d \n", tabMonstre[i]->defense);
            printf("monstre attaque min : %d \n", tabMonstre[i]->attaqueMin);
            printf("monstre attaque max : %d \n", tabMonstre[i]->attaqueMax);
        }
     // ON LANCE L'ATTAQUE 

        int i = 0;
        partie:
        attaquerMonstre(&joueur,tabMonstre[i]);
        
        nbrAttaqueJoueur --;
        if(nbrAttaqueJoueur == 0){
            printf("vous avez atteint le nombre d'attaque autoriser");
            //goto tourmonstre; // non encore  implémenter 
        }
        if(tabMonstre[i]->vie==0){
            printf("le monstre est mort");
        }else{
            printf("le monstre n'est pas mort attaquer encore? 1 pour Oui et 0 pour Non\n");
            int cont;
            scanf("%d",&cont);
            if(cont == 1){
               goto partie; 
            }  
        }
        /*
        printf("voulez vous attaquer ? O pour oui et N pour non ");
        char option; 
        option  = getchar();
        if(option=='o'||option=='O'){
            i++;
            goto partie;
        }
        goto partie;*/

    }
    if(choix == 2){
        // on charge la partie
    }


    // Génère un monstre aléatoire
    /*
    struct Monstre monstre1;
    monstre1.vie = 50;
    monstre1.attaqueMin = 8;
    monstre1.attaqueMax = 15;
    monstre1.defense = 3;

    // Le joueur attaque le monstre
    //attaquerJoueur(&joueur);
    //attaquerMonstre(&joueur,&monstre1);

    // Crée un inventaire vide pour le joueur
    struct Inventaire inventaire;
    inventaire.nbArmes = 0;
    inventaire.nbArmures = 0;
    inventaire.nbPotions = 0;

    // Génère un objet aléatoire et l'ajoute à l'inventaire
    struct Objet objet = genererObjet();
    ajouterObjet(&inventaire, objet);

    // Affiche le contenu de l'inventaire
    printf("Inventaire du joueur :\n");
    printf("Armes :\n");
    for (int i = 0; i < inventaire.nbArmes; i++) {
        printf("Nom : %s, Pouvoir : %d\n", inventaire.armes[i].nom, inventaire.armes[i].pouvoir);
    }
    printf("Armures :\n");
    for (int i = 0; i < inventaire.nbArmures; i++) {
        printf("Nom : %s, Pouvoir : %d\n", inventaire.armures[i].nom, inventaire.armures[i].pouvoir);
    }
    printf("Potions :\n");
    for (int i = 0; i < inventaire.nbPotions; i++) {
        printf("Nom : %s, Pouvoir : %d\n", inventaire.potions[i].nom, inventaire.potions[i].pouvoir);
    }
    */
    return 0;
}

