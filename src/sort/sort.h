//
// Created by Hectorrr on 06/10/2023.
//

#ifndef PROJETS_SORT_H
#define PROJETS_SORT_H

#include "../joueur/joueur.h"
typedef struct Sort {
    char nom[50]; // Nom du sort
    int coutMana; // Coût en mana du sort
    // Effet spécifique du sort (à définir selon votre jeu)
}Sort;

void utiliserSort(Joueur *joueur,Sort sort);

#endif //PROJETS_SORT_H
