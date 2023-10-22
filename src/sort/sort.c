//
// Created by Hectorrr on 06/10/2023.
//
#include "sort.h"

// Fonction pour utiliser un sort
void utiliserSort(Joueur *joueur,Sort sort) {
    if (joueur->mana >= sort.coutMana) {
        // Appliquer l'effet du sort sur le joueur (à définir selon le sort)
        printf("Le joueur utilise le sort : %s\n", sort.nom);

        // Réduire la mana du joueur
        joueur->mana -= sort.coutMana;
    } else {
        printf("Pas assez de mana pour utiliser ce sort.\n");
    }
}