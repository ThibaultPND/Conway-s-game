#if !defined(__CADRE_H__)
#define __CADRE_H__

#include "SDL2/SDL.h"
#include "Project.h"

void renderGrille();
void tileSelectedAndRender(Uint16 x, Uint16 y);
void initGrille(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]);
void RenderTile(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]);

void resetConway(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]);
void lancerConway(bool grille[HAUTEUR_FENETRE][LARGEUR_FENETRE]);


#endif // __CADRE_H__
