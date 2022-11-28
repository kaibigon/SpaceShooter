//
//  AssetManager.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//
#pragma once

#ifndef AssetManager_hpp
#define AssetManager_hpp

#include <stdio.h>
#include <string>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

class AssetManager
{
public:
    
    static AssetManager& GetInstance();
    
    SDL_Surface* GetSurface(std::string filepath);
    
    void free();
    
private:
    AssetManager();
    AssetManager(AssetManager const&);
    std::unordered_map<std::string, SDL_Surface*> m_surfaces;
};

#endif /* AssetManager_hpp */


