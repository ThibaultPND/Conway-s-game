/***************************************************************
**  Auteur : Thibault Chassagne
**  MAJ : 19/10/2023
*  
**  Nom : Jeu de la vie
*  
*?  Description : Ce logiciel à pour but de crée le jeu de la vie.
*
g++ -o prog -Iinclude -Iinclude/SDL2 src/*.cpp -Llib -lSDL2main -lSDL2 -static -DSDL_MAIN_HANDLED && bin\prog.exe
***************************************************************/
#include <Project.h>
#include <SDL2/SDL.h>
#include "TxUtils.h"
#include "globalRenderer.h"
#include "cadre.h"


int main(int argc, char* argv[]) {
    system("cls");
    system("chcp 65001");
    std::cout << "Debut du  programme...\n" << std::endl;
    SDL_Window* window(nullptr);
    try {
        // Initialisation
        project::Application app(window);
        srand(SDL_GetTicks());
        
        // Programme
        bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE];
        initGrille(grille);

        SDL_RenderPresent(gRenderer);
        // Event
        Uint16 mouseX, mouseY;
        SDL_Event event;
        Uint32 startTimer = SDL_GetTicks();
        Uint32 secondTimer = SDL_GetTicks();
        bool ProgramLaunched = true;
        while (ProgramLaunched){
            SDL_Delay(2);
            renderGrille();
            // tileSelectedAndRender(mouseX, mouseY);

            if (SDL_GetTicks()-startTimer > 100){
                startTimer = SDL_GetTicks();
                RenderTile(grille);
                printf("%d\n", SDL_GetTicks() - startTimer);
            }
            

            SDL_RenderPresent(gRenderer);
            SDL_Delay(4);
            while (SDL_PollEvent(&event)){
                switch (event.type) {
                    case SDL_QUIT:
                        ProgramLaunched = false;
                        break;
                    case SDL_MOUSEMOTION:
                        mouseX = event.motion.x;
                        mouseY = event.motion.y;
                    case SDL_MOUSEBUTTONDOWN:
                        if (event.button.button == SDL_BUTTON_LEFT){
                            grille[mouseX/TILE_SCALE][mouseY/TILE_SCALE] = !grille[mouseX/TILE_SCALE][mouseY/TILE_SCALE];
                        }
                        break;
                    case SDL_KEYDOWN:
                        if (event.key.keysym.sym == SDLK_SPACE){
                            lancerConway(grille);
                        }else if (event.key.keysym.sym == SDLK_r){
                            resetConway(grille);
                        }
                        
                    default:
                        break;
                }
            }
            SDL_Delay(5);
            SDL_PumpEvents();
        }
        
        // Libération des ressources
        SDL_DestroyRenderer(gRenderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        std::cout << "Fin du programme...\n" << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Erreur fatale dans le programme principal : " << e.what() << std::endl;

        SDL_DestroyRenderer(gRenderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}