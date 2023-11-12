//
// Created by Hectorrr on 06/10/2023.
//

#ifndef PROJETS_FONCTIONS_H
#define PROJETS_FONCTIONS_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include <curses.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "../monstre/monstre.h"
#include "../joueur/joueur.h"
#include "../objet/objet.h"


#define NOIR      1
#define ROUGE     2
#define VERT      3
#define ORANGE    4
#define BLEU      5
#define MAGENTA   6
#define CYAN      7
#define BLANC     8
#define JAUNE     9

void couleur_char(char c);

// Prototype de la Fonction pour charger l'état du jeu depuis un fichier
void chargerPartie(Joueur *joueur, struct Inventaire *inventaire, char *nomFichier);

// Prototype de la Fonction pour sauvegarder la partie du jeu dans un fichier
void sauvegarderPartie(Joueur joueur, struct Inventaire inventaire, char *nomFichier);

// Prototype pour afficher le menu
void  afficherMenu();
//oid move(int x, int y);

void LancerPartie();

#endif //PROJETS_FONCTIONS_H
