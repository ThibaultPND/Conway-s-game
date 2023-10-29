#include"Project.h"

namespace project
{
Application::Application(SDL_Window*& window ){
    this->pWindow = window;

    // Initialisation de SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        throw std::runtime_error("Erreur lors de l'initialisation de SDL : " + std::string(SDL_GetError()));
    }

    // Création de la fenêtre
    pWindow = SDL_CreateWindow("Conway", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGEUR_FENETRE, HAUTEUR_FENETRE, 0);
    if (pWindow == nullptr) {
        SDL_Quit();
        throw std::runtime_error("Erreur lors de la création de la fenêtre : " + std::string(SDL_GetError()));
    }

    // Création du rendu
    gRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_SOFTWARE);
    if (gRenderer == nullptr) {
        SDL_DestroyWindow(pWindow);
        SDL_Quit();
        throw std::runtime_error("Erreur lors de la création du rendu : " + std::string(SDL_GetError()));
    }

    // if(SDL_RenderSetLogicalSize(gRenderer, LARGEUR_LOGIQUE, HAUTEUR_LOGIQUE)) {
    //     throw std::runtime_error("Erreur lors du changement de taille logique : " + std::string(SDL_GetError()));
    // }
}

Application::~Application() {
    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(pWindow);
    std::cout << "Application détruite !" << std::endl;
}
} // namespace project


void ExitWithError(const char *message){
    SDL_Log("Erreur : %s > %s", message, SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}

