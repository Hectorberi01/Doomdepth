// Created by Hectorrr on 06/10/2023.
//

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
/*void gotoxy(int x, int y) {
    printf("\033[%d;%dH", y, x);
    fflush(stdout);
}*/


void  afficherMenu(){
    printf("\n");
    printf(" \t ________________________________________________________________________________\n");
    printf("\t|                                                                                |\n");
    printf("\t|                          BIENVENUE DANS LE JEU DOOMDEPTH                       |\n");
    printf("\t|________________________________________________________________________________|\n");
    printf("\t|                                                                                |\n");
    printf("\t|                                    MENU                                        |\n");
    printf("\t|________________________________________________________________________________|\n");
    printf("\t|                                                                                |\n");
    printf("\t|                                    1-NOUVELLE PARTIE                           |\n");
    printf("\t|                                                                                |\n");
    printf("\t|                                    2-CHARGER PARTIE                            |\n");
    printf("\t|________________________________________________________________________________|\n");
    printf("\n");
    printf("\n");
}

void couleur_char(char c){
   switch (c) {
      case NOIR    : printf("\033[30m" ); break;
      case ROUGE   : printf("\033[31m" ); break;
      case VERT    : printf("\033[32m" ); break;
      case ORANGE  : printf("\033[33m" ); break;
      case BLEU    : printf("\033[34m" ); break;
      case MAGENTA : printf("\033[35m" ); break;
      case CYAN    : printf("\033[36m" ); break;
      case BLANC   : printf("\033[37m" ); break;
      case JAUNE   : printf("\033[00m" ); break;
      default      : printf("\ncouleur non répertoriée\n");
   }
}

void LancerPartie(){
        srand(time(NULL));    // Initialise le générateur de  nbrmonstres aléatoires avec l'heure actuelle
    int choix;
    afficherMenu(); 
    printf("\033[31m");
    printf("\tENTRER VOTRE CHOIX : ");
    printf("\033[00m");
    scanf(" %d", &choix);

    if(choix == 1){
        Joueur joueur;
        // DÉFINIR LE nbrmonstre DE MONSTRE ENTRE 4 ET 10
        int nbrmonstre = rand()%10 + 4;
        initialiserJoueur(&joueur);
        Objet objet = genererObjet();
        // on affiche l'objet d'attaque ainsi que la puissance de l'arme
        afficherObjet(&objet,&joueur,nbrmonstre);
        printf("\n");
        afficherVie(&joueur);
        printf("\n");

        printf("attaque \n");
        printf("nombre  de montre : %d \n", nbrmonstre);
        
        Monstre *tabMonstre[nbrmonstre];//TABLEAU POUR CONTENIR LES MOSTRES

        //on enrégistre les monstre dans un tableau
        for (int i = 0; i < nbrmonstre ; i++){
            tabMonstre[i] = malloc(sizeof(Monstre));
            *tabMonstre[i] = genererMonstre(); //*_monstre;
        }
        // ON LANCE L'ATTAQUE
        int i = 0;
        int attaque = 0;
        partie:
        attaquerMonstre(&joueur,tabMonstre[i]);
        joueur.attaqueMax--;
        joueur.attaqueMin--;
        attaque++;
        if(attaque == joueur.attaqueMax){
            printf("attaque maximun autoriser atteint");
            goto ATTAQUEMONSTRE; // non encore  implémenter
        }
        if(i == nbrmonstre-1) printf("Félicitation tout les monstres son morts");
        
        if(tabMonstre[i]->vie==0){
            printf("le monstre est mort");
        }else{
            printf("le monstre n'est pas mort attaquer encore? 1 pour Oui et 0 pour Non\n");
            int cont;
            scanf("%d",&cont);
            if(cont == 1){
                goto partie;
            }else if (cont == 0){
                // on vérifie si l'attaque minimun est attaient
                if(attaque < joueur.attaqueMin){
                    printf("attaque minium non atteint");
                    goto partie;
                }else{
                    //sauvegarderPartie(joueur,inventaire,'partiejeu')
                    goto ATTAQUEMONSTRE;
                }  
            }
        }
        /*printf("voulez vous attaquer ? O pour oui et N pour non ");
        char option;
        option  = getchar();
        if(option=='o'||option=='O'){
             i++;
             goto partie;
        }
        goto partie;

        //ATTAQUE DES MONSTRE
        ATTAQUEMONSTRE:
        printf("c'est au tour des monstres de vous attaquer");
        attaquerJoueur(&joueur)*/
        ATTAQUEMONSTRE:

    }
    if(choix == 2){
        // on charge la partie
    }
}