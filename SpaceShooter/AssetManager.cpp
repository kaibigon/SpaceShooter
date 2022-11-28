//
//  AssetManager.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "AssetManager.hpp"

AssetManager::AssetManager(){

}

AssetManager::AssetManager(AssetManager const&){

}

// Is instantiate, exactly 1 instance of our class
AssetManager& AssetManager::GetInstance(){
    static AssetManager* s_instance = new AssetManager;
    return *s_instance;
}

SDL_Surface* AssetManager::GetSurface(std::string filepath){
    auto search = m_surfaces.find(filepath);
    if(search != m_surfaces.end()){
        return m_surfaces[filepath];
    }else{
        SDL_Surface* surface = IMG_Load(filepath.c_str());
        m_surfaces.insert(std::make_pair(filepath,surface));
        return m_surfaces[filepath];
    }
    
    return nullptr;
}

void AssetManager::free()
{
    for (std::pair<std::string, SDL_Surface*> e : m_surfaces)
    {
        SDL_FreeSurface(e.second);
    }
}
