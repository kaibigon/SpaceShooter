//
//  texture_loader.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//

#include "TextureLoader.hpp"

LTexture::LTexture(){
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

LTexture::~LTexture(){
    free();
}

void LTexture::loadFromFile(SDL_Renderer *renender, std::string path){
    free();
    
    SDL_Texture *newTexture = NULL;
    // SDL_Surface *newSurface = IMG_Load(path.c_str());
    
    SDL_Surface *newSurface = AssetManager::GetInstance().GetSurface(path.c_str());
    
    newTexture = SDL_CreateTextureFromSurface(renender, newSurface);
    mWidth = newSurface->w;
    mHeight = newSurface->h;
    
    mTexture = newTexture;
    
//    SDL_FreeSurface(newSurface);
}

void LTexture::loadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor){
    free();
    SDL_Surface *textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    
    if(textSurface == NULL){
        printf( "Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError() );
    }else{
        mTexture = SDL_CreateTextureFromSurface(renender, textSurface);
        mWidth = textSurface->w;
        mHeight = textSurface->h;
        SDL_FreeSurface(textSurface);
    }

}

void LTexture::setAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::render(SDL_Renderer *renderer, int x, int y, int width, int height){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width;
    dst.h = height;
    
    SDL_RenderCopy(renderer, mTexture, NULL, &dst);
}

void LTexture::free(){
    if(mTexture != NULL) {
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

SDL_Texture* LTexture::getTexture(){
    return mTexture;
}

int LTexture::getWidth(){
    return mWidth;
}

int LTexture::getHeight(){
    return mHeight;
}
