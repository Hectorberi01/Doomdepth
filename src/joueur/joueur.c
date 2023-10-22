//
// Created by Hectorrr on 06/10/2023.
//

#include "joueur.h"
#include "../monstre/monstre.h"
#include "../objet/objet.h"
#include "../fonctions/fonctions.h"


/*************************************************************************************************
 * //Fonction pour que le joueur attaque le monstre
 **************************************************************************************************/
void attaquerMonstre(Joueur *joueur,Monstre *monstre) {
    // Calcul des dégâts infligés au monstre
    int degats = rand() % (joueur->attaqueMax - joueur->attaqueMin + 1) + joueur->attaqueMin;

    degats -= monstre->defense;
    if (degats < 0) {
        degats = 0;  // Assurez que les dégâts ne sont pas négatifs
    }
    monstre->vie -= degats;    // Réduit la vie du monstre en fonction des dégâts
    printf("Le joueur inflige %d points de degats au monstre.\n", degats);    // Affiche le résultat de l'attaque
    // Vérifie si le monstre est mort
    if (monstre->vie <= 0) {
        printf("Le monstre est vaincu !\n");
    }
}

// initialise le joueure
Joueur initialiserJoueur(Joueur *joueur){
    joueur->vie= 100;
    joueur->attaqueMin = 10;
    joueur->attaqueMax = 20;
    joueur->defense = 5;
    return *joueur;
}

// affichage de la bare de vie du joueur
void afficherVie(Joueur *joueur){
    //move(5, 16);
    printf("VIE : ");
    for(int i = 0; i < joueur->vie; i++){
        printf("\xB2");
    }
}

/*************************************************************************************************
 * // Fonction pour afficher les caractéristiques de l'objet générer
 **************************************************************************************************/

void afficherObjet(Objet *objet, Joueur *joueur){
    //move(5, 18);
    printf("==================================================================================\n");
    //move(5,19);
    printf("|");
    //move(11,19);
    printf("ARME");
    //move(22,19);
    printf("|");
    //move(28, 19);
    printf("POUVOIR ARME");
    //move(42,19);
    printf("|");
    //move(48, 19);
    printf("ATTAQUE MIN");
    //move(62,19);
    printf("|");
    //move(68, 19);
    printf("ATTAQUE MAX");
    //move(86,19);
    printf("|");
    //move(5,20);
    printf("==================================================================================\n");
    //move(5,21);
    printf("|");
    //move(11,21);
    printf("%s",objet->nom);
    //move(22,21);
    printf("|");
    //move(28, 21);
    printf("%d",objet->pouvoir);
    //move(42,21);
    printf("|");
    //move(48, 21);
    printf("%d",joueur->attaqueMin);
    //move(62,21);
    printf("|");
    //move(68, 21);
    printf("%d",joueur->attaqueMax);
    //move(86,21);
    printf("|");
    //
    
    
    //move(5,22);
    printf("==================================================================================\n");
}

