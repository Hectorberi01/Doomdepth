//
// Created by Hectorrr on 06/10/2023.
//
#include "objet.h"

/*************************************************************************************************
 * // Fonction pour générer un objet aléatoire (dans cet exemple, uniquement des armes)
 **************************************************************************************************/
Objet genererObjet() {
    Objet objet;
    char noms[5][50] = {"Epee", "Hache", "Arc", "Baton", "Dague"};
    strcpy(objet.nom, noms[rand() % 5]); // Sélectionne un nom aléatoire parmi la liste
    objet.pouvoir = rand() % 20 + 10;     // Pouvoir de l'objet entre 10 et 29
    return objet;
}

/*************************************************************************************************
 * // Fonction pour ajouter un objet à l'inventaire du joueur
 **************************************************************************************************/
void ajouterObjet(struct Inventaire *inventaire,Objet objet) {

    // Vérifie le type de l'objet et ajoute-le à la bonne catégorie (armes, armures, potions)

    if (strcmp(objet.nom, "Epee") == 0 || strcmp(objet.nom, "Hache") == 0 || strcmp(objet.nom, "Arc") == 0) {
        inventaire->armes[inventaire->nbArmes] = objet;
        inventaire->nbArmes++;
    } else if (strcmp(objet.nom, "Armure") == 0 || strcmp(objet.nom, "Bouclier") == 0) {
        inventaire->armures[inventaire->nbArmures] = objet;
        inventaire->nbArmures++;
    } else {
        inventaire->potions[inventaire->nbPotions] = objet;
        inventaire->nbPotions++;
    }
}
