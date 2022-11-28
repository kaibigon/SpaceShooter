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
    Free();
}

void LTexture::LoadFromFile(SDL_Renderer *renender, std::string path){
//    free();
    
    SDL_Texture *newTexture = NULL;
    // SDL_Surface *newSurface = IMG_Load(path.c_str());
    
    SDL_Surface *newSurface = AssetManager::GetInstance().GetSurface(path.c_str());
    
    newTexture = SDL_CreateTextureFromSurface(renender, newSurface);
    mWidth = newSurface->w;
    mHeight = newSurface->h;
    
    mTexture = newTexture;
    
//    SDL_FreeSurface(newSurface);
}

void LTexture::LoadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor){
//    free();
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

void LTexture::SetAlpha(Uint8 alpha){
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void LTexture::Render(SDL_Renderer *renderer, int x, int y, int width, int height){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = width;
    dst.h = height;
    
    SDL_RenderCopy(renderer, mTexture, NULL, &dst);
}

void LTexture::Free(){
    if(mTexture != NULL) {
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

SDL_Texture* LTexture::GetTexture(){
    return mTexture;
}

int LTexture::GetWidth(){
    return mWidth;
}

int LTexture::GetHeight(){
    return mHeight;
}

void LTexture::SetWidth(int width)
{
    mWidth = width;
}

void LTexture::SetHeight(int height)
{
    mHeight = height;
}
