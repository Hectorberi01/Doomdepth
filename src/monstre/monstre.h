/*************************************************************************************************
 * AUTEURES: Hector ADJAKPA; Tristan BERDRIN; David MARCELIN
 * DATE:   06/10/2023
 * DESCRIPTION: fichier d'entête du structure monstre; ce fichier contient
 * le prototype des fonctions ainsi que les structures qui ont rapport avec
 * les monstres du projet.
 **************************************************************************************************/


#ifndef PROJETS_MONSTRE_H
#define PROJETS_MONSTRE_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct Monstre {
    int vie;             // Points de vie du monstre
    int attaqueMin;      // Attaque minimale du monstre
    int attaqueMax;      // Attaque maximale du monstre
    int defense;         // Niveau de défense du monstre
} Monstre;

Monstre genererMonstre();

#endif //PROJETS_MONSTRE_H
