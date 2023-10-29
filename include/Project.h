#ifndef __PROJECT_H__
#define __PROJECT_H__

// Inclusions
#include<iostream>
#include<string>
#include<SDL2/SDL.h>
#include "globalRenderer.h"

// Maccros dimension fenêtre
#define HAUTEUR_FENETRE 800
#define LARGEUR_FENETRE 900

#define HAUTEUR_LOGIQUE 36
#define LARGEUR_LOGIQUE 32

#define TILE_SCALE 25


namespace project {

class Application {
    public:
        Application(SDL_Window*& window);
        ~Application();

    private:
        SDL_Window *pWindow;
};

}

#endif // __PROJECT_H__