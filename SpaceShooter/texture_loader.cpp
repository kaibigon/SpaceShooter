//
//  texture_loader.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//

#include "texture_loader.hpp"

LTexture::LTexture(){
    texture = NULL;
    width = 0;
    height = 0;
}

LTexture::~LTexture(){
    free();
}

void LTexture::loadFromFile(SDL_Renderer *renender, std::string path){
    free();
    
    SDL_Texture *newTexture = NULL;
    SDL_Surface *newSurface = IMG_Load(path.c_str());
    
    newTexture = SDL_CreateTextureFromSurface(renender, newSurface);
    width = newSurface->w;
    height = newSurface->h;
    
    texture = newTexture;
    
    SDL_FreeSurface(newSurface);
}

void LTexture::setAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod( texture, alpha );
}

void LTexture::render(SDL_Renderer *renderer){
    SDL_Rect dst;
    dst.x = 0;
    dst.y = 0;
    dst.w = SCREEN_WIDTH;
    dst.h = SCREEN_HEIGHT;
    
    SDL_RenderCopy(renderer, texture, NULL, &dst);
}

void LTexture::free(){
    if(texture != NULL) {
        texture = NULL;
        width = 0;
        height = 0;
    }
}

SDL_Texture* LTexture::getTexture(){
    return texture;
}

int LTexture::getWidth(){
    return width;
}

int LTexture::getHeight(){
    return height;
}
