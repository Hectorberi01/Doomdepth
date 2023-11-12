#include "main.h"


int main()
{
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK,SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION,3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION,3);

    if (SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("Ne peut pas initialiser SDL %s", SDL_GetError());
        exit(1);
    }
     // Initialisation de SDL_image pour la gestion des images
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("SDL_image n'a pas pu s'initialiser! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        return -1;
    }

    // window principale
    SDL_Window* window = SDL_CreateWindow("DoomDepthsC",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,1000,1000,SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!window || renderer == NULL){
        printf("Failed to init window %s", SDL_GetError());
        SDL_DestroyWindow(window);IMG_Quit();SDL_Quit();
        exit(1);
    }
    
    // Effacer l'écran
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);
    // Appelle la fonction de cartographie
    cartographie(renderer);
    SDL_Delay(15000);
    

    // Charger une image pour le personnage
    SDL_Texture* JoueurTexture = NULL;
    SDL_Surface* JoueurSurface = IMG_Load("./img/ho.png");
    if (JoueurSurface == NULL) {
        printf("Erreur lors du chargement de l'image du personnage : %s\n", IMG_GetError());
    } else {
        JoueurTexture = SDL_CreateTextureFromSurface(renderer, JoueurSurface);
        if (JoueurTexture == NULL) {
            printf("Erreur lors de la création de la texture du personnage : %s\n", SDL_GetError());
        }
        SDL_FreeSurface(JoueurSurface);
    }

    // Position du personnage
    int characterX = 50;//SCREEN_WIDTH  - CHARACTER_SIZE ;
    int characterY = 550;//SCREEN_HEIGHT  - CHARACTER_SIZE ;
    int characterVelX = 0;
    int characterVelY = 0;
    // Ajouter d'autres personnages

    puts("OpenGL Loared");
    bool quit = false;
    while (!quit){
        SDL_Event event;
        while (SDL_PollEvent(&event)){
            switch (event.type){
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym){
                        case SDLK_UP:
                            characterVelY = -CHARACTER_SPEED;
                            break;
                        case SDLK_DOWN:
                            characterVelY = CHARACTER_SPEED;
                            break;
                        case SDLK_LEFT:
                            characterVelX  = -CHARACTER_SPEED;
                            break;
                        case SDLK_RIGHT:
                            characterVelX  = CHARACTER_SPEED;
                            break;
                        default:break;
                    }
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                        case SDLK_DOWN:
                            //characterVelY = 0;
                            //break;
                        case SDLK_LEFT:
                        case SDLK_RIGHT:
                            //characterVelX = 0;
                            //break;
                    }
                default: break;
            }
        }

        // Mise à jour de la position du personnage en fonction de la vélocité
        characterX += characterVelX;
        characterY += characterVelY;

        // Vérification des limites de la fenêtre
        if (characterX < 0) {
            characterX = 0;
        }
        if (characterY < 0) {
            characterY = 0;
        }
        if (characterX > SCREEN_WIDTH ) {
            characterX = SCREEN_WIDTH ;
        }
        if (characterY > SCREEN_HEIGHT - CHARACTER_SIZE) {
            characterY = SCREEN_HEIGHT - CHARACTER_SIZE;
        }

         // Effacer l'écran
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Afficher le fond
        // if (backgroundTexture != NULL) {
        //     SDL_RenderCopy(renderer, backgroundTexture, NULL, NULL);
        // }

        // Afficher le personnage
        if (JoueurTexture != NULL) {
            SDL_Rect characterRect = { characterX, characterY, CHARACTER_SIZE, CHARACTER_SIZE };
            SDL_RenderCopy(renderer, JoueurTexture, NULL, &characterRect);
        }
        SDL_RenderPresent(renderer);

    }

    // Libération des ressources
   // SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(JoueurTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}