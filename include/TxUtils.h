#ifndef __TXUTILS_H__
    #define __TXUTILS_H__
    #include "globalRenderer.h"
    #include <iostream>
    #include <SDL2/SDL.h>

    SDL_Texture *LoadTexture ( const char *path );
    SDL_Texture *LoadingTextureAndRect ( const char *path, SDL_Rect &rect, Uint16 x = 0, Uint16 y = 0 );
    SDL_Texture *LoadingTextureAndRect ( SDL_Texture *texture, SDL_Rect &rect, Uint16 x = 0, Uint16 y = 0 );
#endif // __TXUTILS__H_