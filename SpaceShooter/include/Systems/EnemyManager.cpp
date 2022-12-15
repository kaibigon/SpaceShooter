//
//  EnemyManager.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/15.
//

#include "EnemyManager.hpp"

EnemyManager::EnemyManager(){

}

EnemyManager::EnemyManager(EnemyManager const&){

}

EnemyManager& EnemyManager::GetInstance(){
    static EnemyManager* s_instance = new EnemyManager;
    return *s_instance;
}

// TODO: passing player all the way here is not fun, replace player here with gCoordinator->FindWithTag( which is another TODO:( )
void EnemyManager::SpawnEnemy(std::shared_ptr<Coordinator> &gCoordinator, std::shared_ptr<EnemySystem> enemySystem, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender)
{
    Entity enemy = gCoordinator->CreateEntity();
    gCoordinator->AddComponent(enemy, TransformComponent{
//        .x = 100 + (float)mNumOfEnemies * 20,
//        .y = 100 + (float)mNumOfEnemies * 20,
        .x = 0,
        .y = 0,
        .z = 0,
    });
    gCoordinator->AddComponent(enemy, MovementComponent{
        .velX = 0,
        .velY = 0,
        .velValue = 100,
        .accer = 0,
    });
    gCoordinator->AddComponent(enemy, TextureComponent{});
    gCoordinator->AddComponent(enemy, EnemyComponent{});
    
    renderSystem->LoadTexture(gCoordinator, enemy, renender, "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(gCoordinator, enemy, 20, 20);
    
    gCoordinator->SetEntitiesForSystem<RenderSystem>();
    gCoordinator->SetEntitiesForSystem<MovementSystem>();
    gCoordinator->SetEntitiesForSystem<EnemySystem>();
    
    mNumOfEnemies ++;
//    Entity player = gCoordinator->FindWithTag("Player");
}

void EnemyManager::Update(std::shared_ptr<Coordinator> &gCoordinator, std::shared_ptr<EnemySystem> enemySystem, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, Entity player)
{
    if (SDL_GetTicks() - mLastSpawnTime > mSpawnInterval)
    {
        SpawnEnemy(gCoordinator, enemySystem, renderSystem, renender);
        mLastSpawnTime = SDL_GetTicks();
    }
    enemySystem->ChasePlayer(gCoordinator, player);
}


