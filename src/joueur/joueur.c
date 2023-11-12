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
        couleur_char(VERT);
        printf("#");
        printf("\033[00m");
    }
}

/*************************************************************************************************
 * // Fonction pour afficher les caractéristiques de l'objet générer
 **************************************************************************************************/

void afficherObjet(Objet *objet, Joueur *joueur, int nbr){
    printf("\t ________________________________________________________________________________\n");
    printf("\t|                                                                                |\n");
    printf("\t  ARME                               %s\n",objet->nom);
    printf("\t|                                                                                |\n");
    printf("\t  POUVOIR ARME                       %d\n",objet->pouvoir);
    printf("\t|                                                                                |\n");
    printf("\t  ATTAQUE MIN                        %d\n",joueur->attaqueMin);
    printf("\t|                                                                                |\n");
    printf("\t  ATTAQUE MAX                        %d\n",joueur->attaqueMax);
    printf("\t|                                                                                |\n");
    printf("\t  TOTAL MONSTRE                      %d\n",nbr);
    printf("\t|________________________________________________________________________________|\n");
}

