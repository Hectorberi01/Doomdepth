/*************************************************************************************************
 * AUTEURES: Hector ADJAKPA; Tristan BERDRIN; David MARCELIN
 * DATE:   06/10/2023
 * DESCRIPTION: fichier d'entête du structure joueur; ce fichier contient
 * le prototype des fonctions ainsi que les structures qui ont rapport avec
 * le joueur du projet.
 **************************************************************************************************/

#ifndef PROJETS_JOUEUR_H
#define PROJETS_JOUEUR_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../monstre/monstre.h"
#include "../objet/objet.h"

// Structure représentant le joueur

typedef struct Joueur{
    int vie;             // Points de vie du joueur
    int attaqueMin;      // Attaque minimale du joueur
    int attaqueMax;      // Attaque maximale du joueur
    int defense;         // Niveau de défense du joueur
    int mana;
}Joueur;

void attaquerMonstre(Joueur *joueur, Monstre *monstre);

void attaquerJoueur(Joueur *joueur);

void  afficherObjet(struct Objet *objet, Joueur  *joueur);

Joueur initialiserJoueur(Joueur *joueur);

void afficherVie(Joueur *joueur);

#endif //PROJETS_JOUEUR_H
