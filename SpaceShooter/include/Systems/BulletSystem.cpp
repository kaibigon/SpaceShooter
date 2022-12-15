//
//  BulletSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/11.
//

#include "BulletSystem.hpp"

void BulletSystem::SpawnBullet(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction)
{
    Entity bullet = gCoordinator->CreateEntity();
    gCoordinator->AddComponent(bullet, TransformComponent{
        .x = x,
        .y = y,
        .z = 0,
    });
    gCoordinator->AddComponent(bullet, MovementComponent{
        .velX = 0,
        .velY = 0,
        .velValue = 200,
        .accer = 0,
    });
    gCoordinator->AddComponent(bullet, BulletComponent{
        .id = bullet,
        .direction = direction,
        .speed = 10,
        .maxLifeTime = 1000,
        .spawnLifeTime = SDL_GetTicks(),
    });
    gCoordinator->AddComponent(bullet, TextureComponent{});
    
    renderSystem->LoadTexture(gCoordinator, bullet, renender, "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(gCoordinator, bullet, 20, 20);
    
    gCoordinator->SetEntitiesForSystem<RenderSystem>();
    gCoordinator->SetEntitiesForSystem<MovementSystem>();
    gCoordinator->SetEntitiesForSystem<BulletSystem>();

    auto& movement = gCoordinator->GetComponent<MovementComponent>(bullet);
    
    switch( direction )
    {
        case Up:
            movement.velY -= movement.velValue; break;
        case Down:
            movement.velY += movement.velValue; break;
        case Left:
            movement.velX -= movement.velValue; break;
        case Right:
            movement.velX += movement.velValue; break;
    }
}

void BulletSystem::DestoryBullet(std::shared_ptr<Coordinator>& gCoordinator, Entity bullet)
{
    // if exceed lifetime, destroy
    // if collide with emenies, destroy
    gCoordinator->DestroyEntity(bullet);
}

void BulletSystem::OnCollisionEvent(std::shared_ptr<Coordinator>& gCoordinator, Entity bullet)
{
    DestoryBullet(gCoordinator, bullet);
    //update signature
    
}

void BulletSystem::Update(std::shared_ptr<Coordinator> &gCoordinator)
{
    for(auto const& entity : mEntities)
    {
        auto& bulletComponent = gCoordinator->GetComponent<BulletComponent>(entity);
        if (SDL_GetTicks() - bulletComponent.spawnLifeTime > bulletComponent.maxLifeTime )
        {
            DestoryBullet(gCoordinator, entity);
            // TODO: this is soooo bad
            gCoordinator->RemoveEntityFromSystem<MovementSystem>(entity);
            gCoordinator->RemoveEntityFromSystem<RenderSystem>(entity);
            gCoordinator->RemoveEntityFromSystem<BulletSystem>(entity);
            // TODO: also should reconsider when removing from a set, things happen, put break for skipping current frame for now
            break;
        }
    }
}

