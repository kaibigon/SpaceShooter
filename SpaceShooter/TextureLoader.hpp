//
//  texture_loader.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/26.
//
#pragma once
#ifndef TextureLoader_hpp
#define TextureLoader_hpp

#include <stdio.h>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "consts.h"
#include "AssetManager.hpp"

#endif /* texture_loader_hpp */

class LTexture {
    
public:
    
    LTexture();
    
    ~LTexture();
    
    void loadFromFile(SDL_Renderer *renderer, std::string path);
    
    void loadFromRendereredText(TTF_Font *font, SDL_Renderer *renender, std::string textureText, SDL_Color textColor);
    
    void free();
    
    SDL_Texture* getTexture();
    
    void setAlpha(Uint8 alpha);
    
    void render(SDL_Renderer *renderer, int x, int y, int width, int height);
    
    int getWidth();
    
    int getHeight();
    
private:
    SDL_Texture *mTexture;
    
    int mWidth;
    int mHeight;
};
