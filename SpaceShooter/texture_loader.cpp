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
    
    SDL_FreeSurface(newSurface);
    texture = newTexture;
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
