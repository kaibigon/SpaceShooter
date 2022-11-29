//
//  texture_loader.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//

#include "TextureComponent.hpp"

TextureComponent::TextureComponent()
{
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
}

TextureComponent::~TextureComponent()
{
    Free();
}

void TextureComponent::LoadFromFile(SDL_Renderer *renender, std::string path)
{
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

void TextureComponent::LoadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor)
{
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

void TextureComponent::SetAlpha(Uint8 alpha)
{
    SDL_SetTextureAlphaMod( mTexture, alpha );
}

void TextureComponent::Render()
{
    printf("nmsl, imrendering\n");
    SDL_RenderCopy(mRenderer, mTexture, NULL, &mDst);
}

void TextureComponent::SetRenderConfig(SDL_Renderer *renderer, int x, int y, int width, int height)
{
    mDst.x = x;
    mDst.y = y;
    mDst.w = width;
    mDst.h = height;
    mRenderer = renderer;
//    SDL_RenderCopy(renderer, mTexture, NULL, &dst);
}

void TextureComponent::Free()
{
    if(mTexture != NULL) {
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

SDL_Texture* TextureComponent::GetTexture()
{
    return mTexture;
}

int TextureComponent::GetWidth()
{
    return mWidth;
}

int TextureComponent::GetHeight()
{
    return mHeight;
}

void TextureComponent::SetWidth(int width)
{
    mWidth = width;
}

void TextureComponent::SetHeight(int height)
{
    mHeight = height;
}
