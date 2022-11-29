//
//  EntityManager.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/29.
//

#include "EntityManager.hpp"

void EntityManager::Update()
{
    for (auto& e: entities)
    {
        e->Update();
    }
}


void EntityManager::Render()
{
    for (auto& e: entities)
    {
        e->Render();
    }
}

void EntityManager::Refresh()
{
    entities.erase(std::remove_if(std::begin(entities), std::end(entities),
                                  [](const std::unique_ptr<GameEntity> &mEntity){
        return !mEntity->IsActive();
    }),std::end(entities));
}

GameEntity& EntityManager::AddEntity()
{
    GameEntity* e = new GameEntity();
    std::unique_ptr<GameEntity> uPtr{e};
    entities.emplace_back(std::move(uPtr));
    return *e;
}
