// Created by Hectorrr on 06/10/2023.
//
#include <ncurses.h>
#include "fonctions.h"
#include "../joueur/joueur.h"
/*************************************************************************************************
 * // Fonction pour sauvegarder l'état du jeu dans un fichier
 **************************************************************************************************/
void sauvegarderPartie( Joueur joueur, struct Inventaire inventaire, char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "wb"); // Ouvre le fichier en mode binaire pour sauvegarder les structures

    if (fichier != NULL) {
        // Écrit les données du joueur dans le fichier
        fwrite(&joueur, sizeof(Joueur), 1, fichier);

        // Écrit les données de l'inventaire dans le fichier
        fwrite(&inventaire, sizeof(struct Inventaire), 1, fichier);

        fclose(fichier);
        printf("Partie sauvegardée avec succes.\n");
    } else {
        printf("Erreur lors de la sauvegarde de la partie.\n");
    }
}


/*************************************************************************************************
 * // // Fonction pour charger la partie
 **************************************************************************************************/

void chargerPartie(Joueur *joueur, struct Inventaire *inventaire, char *nomFichier) {
    FILE *fichier = fopen(nomFichier, "rb"); // Ouvre le fichier en mode binaire pour charger les structures

    if (fichier != NULL) {
        // Lit les données du joueur depuis le fichier
        fread(joueur, sizeof(Joueur), 1, fichier);

        // Lit les données de l'inventaire depuis le fichier
        fread(inventaire, sizeof(struct Inventaire), 1, fichier);

        fclose(fichier);
        printf("Partie chargée avec succès.\n");
    } else {
        printf("Erreur lors du chargement de la partie.\n");
    }
}

//COORD coord = { 0, 0 };

//void wmove(int x, int y) {
    //coord.X = x; coord.Y = y;
    //SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}

void  afficherMenu(){
    //move(x/17, y/5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 BIENVENUE DANS LE JEU DOOMDEPTH  \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\n");

    //wmove(win,5, 6);
    printf("==================================================================================\n");
    //wmove(win,5,7);
    printf("|");
    //wmove(win,40,7);
    printf("MENU");
    //wmove(win,86,7);
    printf("|\n");
    //wmove(win,5, 8);
    printf("==================================================================================\n");
    //wmove(win,5,9);
    printf("|");
    //wmove(win,35,9);
    printf("1-NOUVELLE PARTIE");
    //wmove(win,86,9);
    printf("|\n");
    //wmove(win,5, 10);
    printf("==================================================================================\n");
    //wmove(win,5, 11);
    printf("|");
    //wmove(win,35,11);
    printf("2-CHARGER PARTIE ");
    //wmove(win,86,11);
    printf("|\n");
    //wmove(win,5, 12);
    printf("==================================================================================\n");
    //wmove(win,5, 13);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 CHOISISSEZ UNE OPTION \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\n");
    //refresh();
}