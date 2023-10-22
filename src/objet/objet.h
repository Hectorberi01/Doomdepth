/*************************************************************************************************
 * AUTEURES: Hector ADJAKPA; Tristan BERDRIN; David MARCELIN
 * DATE:   06/10/2023
 * DESCRIPTION: fichier d'entête du structure objet ; ce fichier contient
 * le prototype des fonctions ainsi que les structures qui ont rapport avec
 * les objets générés dans le projet.
 **************************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifndef PROJETS_OBJET_H
#define PROJETS_OBJET_H

// Structure représentant un objet (arme, armure, potion, etc.)
typedef struct Objet {
    char nom[50];  // Nom de l'objet
    int pouvoir;   // Pouvoir de l'objet (dégâts pour une arme, défense pour une armure, etc.)
} Objet;

//Structure représentant l'inventaire du joueur
struct Inventaire {
    Objet armes[5];   // Tableau d'objets pour les armes (le joueur peut porter jusqu'à 5 armes)
    Objet armures[5]; // Tableau d'objets pour les armures (le joueur peut porter jusqu'à 5 armures)
    Objet potions[10]; // Tableau d'objets pour les potions (le joueur peut porter jusqu'à 10 potions)
    int nbArmes;   // Nombre d'armes dans l'inventaire
    int nbArmures; // Nombre d'armures dans l'inventaire
    int nbPotions; // Nombre de potions dans l'inventaire
};

struct Objet genererObjet();


#endif //PROJETS_OBJET_H
