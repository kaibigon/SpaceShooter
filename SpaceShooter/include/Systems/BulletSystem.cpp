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
    });
    
    gCoordinator->AddComponent(bullet, TextureComponent{});
    
    renderSystem->LoadTexture(gCoordinator, bullet, renender, "./SpaceShooter/Assets/dot.bmp");
    renderSystem->SetRenderRange(gCoordinator, bullet, 20, 20);
    gCoordinator->SetEntitiesForSystem<RenderSystem>();
    gCoordinator->SetEntitiesForSystem<MovementSystem>();

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
