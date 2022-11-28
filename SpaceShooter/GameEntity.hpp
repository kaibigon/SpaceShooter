//
//  gameEntity.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#ifndef GameEntity_hpp
#define GameEntity_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include "TextureLoader.hpp"

class GameEntity
{
public:
    
    GameEntity();
    
    GameEntity(SDL_Renderer *renderer);
    
    ~GameEntity(); // TODO: should find a way to proper loop through components to free them
    
    void Update();
    
    void Render();
    
    void SetPosX(int posX);
    void SetPosY(int posY);
    
    void AddTextureComponent();
    void AddTextureComponent(std::string filepath);
    LTexture& GetTextureComponent();
    
    SDL_Renderer* GetRenderer();
    
    int GetPosX();
    int GetPosY();
    
private:
    
    int mEntityId; // TODO:
    
    // actually by ecs design, these attributes should be component attached to this entity?
    // forget it, make they are just what they are now -.-
    LTexture* mTexture;
    SDL_Renderer* mRenderer;
    
    // TODO: could be a vec2 but Im lazy
    int mPosX;
    int mPosY;
    
};
#endif /* gameEntity_hpp */
