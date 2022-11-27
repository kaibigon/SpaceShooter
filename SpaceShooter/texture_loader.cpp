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

void LTexture::loadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor){
    free();
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if(textSurface == NULL){
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }else{
        texture = SDL_CreateTextureFromSurface(renender, textSurface);
        width = textSurface->w;
        height = textSurface->h;
        SDL_FreeSurface(textSurface);
    }

}

void LTexture::setAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod( texture, alpha );
}

void LTexture::render(SDL_Renderer *renderer, int x, int y, int width, int height){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width;
    dst.h = height;
    
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
