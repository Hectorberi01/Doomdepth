//
// Created by Hectorrr on 06/10/2023.
//
#include <stdio.h>
#include <stdlib.h>
#include "monstre.h"
#include "../joueur/joueur.h"


/*************************************************************************************************
 * // Fonction pour générer un monstre aléatoire
 **************************************************************************************************/
Monstre genererMonstre() {
    Monstre monstre;
    // Génération aléatoire des statistiques du monstre
    monstre.vie = rand() % 51 + 50;        // Vie entre 50 ET 100 
    monstre.attaqueMin = rand() % 20 + 10;  // Attaque minimale entre 10 et 29
    monstre.attaqueMax = monstre.attaqueMin + rand() % 20; // Attaque maximale entre attaqueMin et attaqueMin + 19
    monstre.defense = rand() % 10;          // Défense entre 0 et 9
    return monstre;
}

/*************************************************************************************************
 * // Fonction pour que le monstre attaque le joueur
 **************************************************************************************************/

void attaquerJoueur(Joueur* joueur) {
    // Calcul des dégâts infligés au joueur
    int degats = rand() % (joueur->attaqueMax - joueur->attaqueMin + 1) + joueur->attaqueMin;
    degats -= joueur->defense;
    if (degats < 0) {
        degats = 0;  // Assurez-vous que les dégâts ne sont pas négatifs
    }
    joueur->vie -= degats;    // Réduit la vie du joueur en fonction des dégâts
    // Affiche le résultat de l'attaque
    printf("Le monstre inflige %d points de degats au joueur.\n", degats);

    // Vérifie si le joueur est mort
    if (joueur->vie <= 0) {
        printf("Le joueur est vaincu !\n");
    }
}