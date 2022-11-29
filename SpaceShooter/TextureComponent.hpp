//
//  texture_loader.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//
#pragma once
#ifndef TextureComponent_hpp
#define TextureComponent_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

//#include "consts.h"
#include "AssetManager.hpp"
#include "Component.hpp"
#include "ECS.h"

class TextureComponent : public Component {
    
public:
    
    TextureComponent();
    
    ~TextureComponent();
    
    void LoadFromFile(SDL_Renderer *renderer, std::string path);
    
    void LoadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor);
    
    void Free();
    
    SDL_Texture* GetTexture();
    
    void SetAlpha(Uint8 alpha);
    
    void Render();
    
    void SetRenderConfig(SDL_Renderer *renderer, int x, int y, int width, int height);
    
    int GetWidth();
    
    int GetHeight();
    
    void SetWidth(int width);
    
    void SetHeight(int height);
    
private:
    SDL_Texture *mTexture;
    SDL_Renderer *mRenderer;
    int mWidth;
    int mHeight;
    SDL_Rect mDst;
};
#endif /* texture_loader_hpp */
