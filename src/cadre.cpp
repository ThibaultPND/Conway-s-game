#include "cadre.h"

void renderGrille(){
    bool blanc;
    for (int i = 1; i < HAUTEUR_LOGIQUE+1; i++) {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(gRenderer, TILE_SCALE*i, 0, TILE_SCALE*i, HAUTEUR_FENETRE);
    }
    for (int j = 1; j < HAUTEUR_LOGIQUE+1; j++) {
        SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(gRenderer, 0, TILE_SCALE*j, LARGEUR_FENETRE, TILE_SCALE*j);
    }
    SDL_Rect rect = {
        .x = 0,
        .y = 0,
        .w = LARGEUR_FENETRE,
        .h = HAUTEUR_FENETRE
    };
    SDL_RenderDrawRect(gRenderer, &rect);
}

void tileSelectedAndRender(Uint16 x, Uint16 y) {

    x /= TILE_SCALE;
    y /= TILE_SCALE;

    SDL_Rect rect = {
        .x = x*TILE_SCALE,
        .y = y*TILE_SCALE,
        .w = TILE_SCALE+1,
        .h = TILE_SCALE+1
    };
    SDL_SetRenderDrawColor(gRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderDrawRect(gRenderer, &rect);
}

void RenderTile(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]) {
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(gRenderer);
    renderGrille();
    SDL_SetRenderDrawColor(gRenderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    for (int i = 0; i < HAUTEUR_FENETRE; i++){
        for (int j = 0; j < LARGEUR_FENETRE; j++){
            if( grille[i][j] ){
                SDL_Rect rect = {
                    .x = (i*TILE_SCALE)+1,
                    .y = (j*TILE_SCALE)+1,
                    .w = TILE_SCALE-1,
                    .h = TILE_SCALE-1
                };
                SDL_RenderFillRect(gRenderer, &rect);
            }
        }   
    }
}

void initGrille(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]) {
    for (int i = 0; i < HAUTEUR_FENETRE; i++){
        for (int j = 0; j < LARGEUR_FENETRE; j++){
            grille[i][j] = false;
        }   
    }
    grille[10][30] = true;
}

void lancerConway(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]){
    bool nouvelleGrille[HAUTEUR_FENETRE][LARGEUR_FENETRE];
    int nombreAutour = 0;
    for (int i = 1; i < HAUTEUR_FENETRE-1; i++){
        for (int j = 1; j < LARGEUR_FENETRE-1; j++){
            for (int k = -1; k < 2; k++){
                for (int l = -1; l < 2; l++){
                    if (grille[i+k][j+l] == true){
                        nombreAutour++;
                    }
                }
            }
            if (grille[i][j] == false){
                if (nombreAutour == 3){
                    nouvelleGrille[i][j] = true;
                }
                
            }else {
                nombreAutour--;
                if (nombreAutour == 2 || nombreAutour == 3){
                    nouvelleGrille[i][j] = true;
                }else if (nombreAutour < 2){
                    nouvelleGrille[i][j] = false;
                }else if (nombreAutour > 3){
                    nouvelleGrille[i][j] = false;
                }
            }

            nombreAutour = 0;
        }   
    }
    for (int i = 0; i < HAUTEUR_LOGIQUE; i++) {
        for (int j = 0; j < LARGEUR_LOGIQUE; j++){
            grille[i][j] = nouvelleGrille[i][j];
        }
        
    }
    
    
}

void resetConway(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]) {
    for (int i = 0; i < HAUTEUR_FENETRE; i++){
        for (int j = 0; j < LARGEUR_FENETRE; j++){
            grille[i][j] = false;
        }   
    }
}