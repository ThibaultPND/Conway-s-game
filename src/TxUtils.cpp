#include "TxUtils.h"

SDL_Texture *LoadTexture( const char *path){
    SDL_Surface *imageSurface = nullptr;
    SDL_Texture *imageTexture = nullptr;

    imageSurface = SDL_LoadBMP(path);
    if( imageSurface == nullptr ){
        throw std::runtime_error("Surface \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    imageTexture = SDL_CreateTextureFromSurface( gRenderer , imageSurface );
    if(imageTexture == nullptr){
        throw std::runtime_error("Texture \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    SDL_FreeSurface( imageSurface );

    return imageTexture;
}

SDL_Texture *LoadingTextureAndRect ( const char *path, SDL_Rect &rect, Uint16 x, Uint16 y ){
    SDL_Surface *imageSurface = nullptr;
    SDL_Texture *imageTexture = nullptr;

    imageSurface = SDL_LoadBMP(path);
    if( imageSurface == nullptr ){
        throw std::runtime_error("Surface \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    imageTexture = SDL_CreateTextureFromSurface( gRenderer , imageSurface );
    if(imageTexture == nullptr){
        throw std::runtime_error("Texture \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));
    }
    SDL_FreeSurface( imageSurface );

    rect.x =  x;
    rect.y = y;
    if ( SDL_QueryTexture(imageTexture, NULL, NULL, &rect.w, &rect.h) )
        throw std::runtime_error("Rect \""+ std::string(path)+ "\" : " + std::string(SDL_GetError()));

    return imageTexture;
}

SDL_Texture *LoadingTextureAndRect ( SDL_Texture *texture, SDL_Rect &rect, Uint16 x, Uint16 y ){

    if(texture == nullptr){
        throw std::runtime_error("Texture :"+ std::string(SDL_GetError()));
    }

    rect.x =  x;
    rect.y = y;
    if ( SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h) )
        throw std::runtime_error("Rect :"+ std::string(SDL_GetError()));

    return texture;
}