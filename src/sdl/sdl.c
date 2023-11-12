#include "sdl.h"

void cartographie(SDL_Renderer *renderer) {
    char room[SCREEN_HEIGHT / CELL_SIZE][SCREEN_WIDTH / CELL_SIZE];

    // Initialise le générateur de nombres aléatoires
    srand((unsigned)time(NULL));

    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++) {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++) {
            int randNum = rand() % 2;
            if (randNum == 1) {
                room[i][j] = '.';
            } else {
                room[i][j] = '#';
            }
        }
    }
    // Dessine la carte
    for (int i = 0; i < SCREEN_HEIGHT / CELL_SIZE; i++) {
        for (int j = 0; j < SCREEN_WIDTH / CELL_SIZE; j++) {
            SDL_Rect cellRect = {j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            if (room[i][j] == '.') {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);  // Blanc pour une cellule vide
            } else {
                SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // Noir pour une cellule pleine
            }
            SDL_RenderFillRect(renderer, &cellRect);
        }
    }

    SDL_RenderPresent(renderer);
}
