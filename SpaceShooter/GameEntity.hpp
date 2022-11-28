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
#include "TextureComponent.hpp"
#include "TransformComponent.hpp"
#include "MovementComponent.hpp"

class GameEntity
{
public:
    
    GameEntity();
    
    GameEntity(SDL_Renderer *renderer);
    
    ~GameEntity(); // TODO: should find a way to proper loop through components to free them
    
    void Update();
    void Render();
    
    void AddTextureComponent();
    void AddTextureComponent(std::string filepath);
    TextureComponent& GetTextureComponent();
    
    void AddTransformComponent();
    TransformComponent& GetTransformComponent();
    
    void AddMovementComponent();
    MovementComponent& GetMovementComponent();
    
    SDL_Renderer* GetRenderer();
    
private:
    
    int mEntityId; // TODO:
    
    // by ecs design, all of these attributes should actually be components attached to this entity
    // but forget it, they are just what they are now -.-
    SDL_Renderer* mRenderer;
    
    TextureComponent* mTexture;
    TransformComponent* mTransform;
    MovementComponent* mMovement;
};
#endif /* gameEntity_hpp */
