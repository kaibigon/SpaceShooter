//
//  InputSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/12.
//

#include "InputSystem.hpp"

void InputSystem::HandleMovementInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e)
{
    for (auto const& entity : mEntities)
    {
        if(gCoordinator->HasTag(entity) &&
           !std::strcmp(gCoordinator->GetTag()[entity], "Player"))
        {
            auto& movement = gCoordinator->GetComponent<MovementComponent>(entity);
            if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_w: movement.velY -= movement.velValue; break;
                    case SDLK_s: movement.velY += movement.velValue; break;
                    case SDLK_a: movement.velX -= movement.velValue; break;
                    case SDLK_d: movement.velX += movement.velValue; break;
                }
            }
            else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_w: movement.velY += movement.velValue; break;
                    case SDLK_s: movement.velY -= movement.velValue; break;
                    case SDLK_a: movement.velX += movement.velValue; break;
                    case SDLK_d: movement.velX -= movement.velValue; break;
                }
            }
            }else{
            }
    }
    
}

void InputSystem::HandleShootInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction, std::shared_ptr<BulletSystem> bulletSystem)
{
    for(auto const& entity : mEntities)
    {
        if(gCoordinator->HasTag(entity) &&
           !std::strcmp(gCoordinator->GetTag()[entity], "Player"))
        {
            auto& transform = gCoordinator->GetComponent<TransformComponent>(entity);
            
            if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
            {
                switch( e.key.keysym.sym )
                {
                    case SDLK_UP:
                        bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Up);
                        break;
                    case SDLK_DOWN:
                        bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Down);
                        break;
                    case SDLK_LEFT:
                        bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Left);
                        break;
                    case SDLK_RIGHT:
                        bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Right);
                        break;
                }
            }
            else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
            {
                switch( e.key.keysym.sym )
                {

                }
            }
            }else{
            }
    }
}

