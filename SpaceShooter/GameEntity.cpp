//
//  gameEntity.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/28.
//

#include "GameEntity.hpp"

GameEntity::GameEntity(){

}

GameEntity::GameEntity(SDL_Renderer *renderer)
{
    mRenderer = renderer;
}

GameEntity::~GameEntity()
{

}

void GameEntity::Update()
{
    for (auto& c:components)
    {
        c->Update();
    }
}

void GameEntity::Render()
{
    for ( auto& c : components)
    {
        c->Render();
    }
}

SDL_Renderer* GameEntity::GetRenderer()
{
    return mRenderer;
}
