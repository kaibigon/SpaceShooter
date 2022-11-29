//
//  gameEntity.hpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#pragma once
#ifndef GameEntity_hpp
#define GameEntity_hpp

#include <stdio.h>
#include <vector>
#include <SDL2/SDL.h>
#include <bitset>
#include <array>

#include "Component.hpp"
#include "TextureComponent.hpp"
#include "TransformComponent.hpp"
#include "MovementComponent.hpp"
#include "ECS.h"

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
    
    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... mArgs)
    {
        T* c(new T(std::forward<TArgs>(mArgs)...));
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;
        
        c->init();
        return *c;
    }
    
private:
    
    int mEntityId; // TODO:
    
    // by ecs design, all of these attributes should actually be components attached to this entity
    // but forget it, they are just what they are now -.-
    SDL_Renderer* mRenderer;
    
    TextureComponent* mTexture;
    TransformComponent* mTransform;
    MovementComponent* mMovement;
    
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitset componentBitset;
    
};
#endif /* gameEntity_hpp */
