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
#include "ECS.h"

class GameEntity
{
public:
    
    GameEntity();
    
    GameEntity(SDL_Renderer *renderer);
    
    ~GameEntity(); // TODO: should find a way to proper loop through components to free them
    
    void Update();
    void Render();
    bool IsActive() {return mActive;}
    void Destory();
    
    SDL_Renderer* GetRenderer();

    // code from : https://www.youtube.com/watch?v=XsvI8Sng6dk&list=PLhfAbcv9cehhkG7ZQK0nfIGJC_C-wSLrx&index=9
    template <typename T>
    bool HasComponent() const
    {
        return componentBitset[getComponentTypeID<T>()];
    }
    
    template <typename T, typename... TArgs>
    T& AddComponent(TArgs&&... mArgs)
    {
        // T* c = new T(std::forward<TArgs>(mArgs)...);
        T* c = new T(mArgs...);
        c->entity = this;
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));
        componentArray[getComponentTypeID<T>()] = c;
        componentBitset[getComponentTypeID<T>()] = true;
        
        c->Init();
        return *c;
    }
    
    template <typename T>
    T& GetComponent() const
    {
        auto ptr(componentArray[getComponentTypeID<T>()]);
        return *static_cast<T*>(ptr);
    }
    
private:
    
    static int mEntityId; // TODO:
    bool mActive = true;
    
    SDL_Renderer* mRenderer;
    
    std::vector<std::unique_ptr<Component>> components;
    ComponentArray componentArray;
    ComponentBitset componentBitset;
    
};
#endif /* gameEntity_hpp */
