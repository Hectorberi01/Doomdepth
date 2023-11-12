
// Définir la taille de chaque cellule sur la carte

#ifndef PROJETS_SDL_H
#define PROJETS_SDL_H
#include <SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>

#define CELL_SIZE 20

SDL_Surface *background  = NULL ;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int CHARACTER_SIZE = 50;
const double CHARACTER_SPEED = 1;
const int MENU_WIDTH = SCREEN_WIDTH;
const int MENU_HEIGHT = 100;

typedef struct Character {
    int x;
    int y;
    int velX;
    int velY;
    SDL_Texture* texture;
}Character;

void cartographie(SDL_Renderer *renderer);
#endif //PROJETS_MONSTRE_H