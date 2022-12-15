//
//  InputSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/12/12.
//

#include "InputSystem.hpp"

void InputSystem::HandleMovementInput(std::shared_ptr<Coordinator>& gCoordinator)
{
    for (auto const& entity : mEntities)
    {
        if(gCoordinator->HasTag(entity) && !std::strcmp(gCoordinator->GetTag()[entity], "Player"))
        {
            // handle movement input
            const Uint8* keystates = SDL_GetKeyboardState(NULL);
            
            auto& movement = gCoordinator->GetComponent<MovementComponent>(entity);
            
            if( keystates[SDL_SCANCODE_W] ^ keystates[SDL_SCANCODE_S])
            {
                movement.velY =  keystates[SDL_SCANCODE_W]?
                                -keystates[SDL_SCANCODE_W] * movement.velValue:
                                 keystates[SDL_SCANCODE_S] * movement.velValue;
            }
            else
            {
                movement.velY = 0;
            }
            
            if( keystates[SDL_SCANCODE_A] ^ keystates[SDL_SCANCODE_D])
            {
                movement.velX = keystates[SDL_SCANCODE_A]?
                               -keystates[SDL_SCANCODE_A] * movement.velValue:
                                keystates[SDL_SCANCODE_D] * movement.velValue;
            }
            else
            {
                movement.velX = 0;
            }
        }
    }
}

void InputSystem::HandleShootingInput(std::shared_ptr<Coordinator>& gCoordinator, std::shared_ptr<RenderSystem> renderSystem, SDL_Renderer *renender, float x, float y, Direction direction, std::shared_ptr<BulletSystem> bulletSystem)
{
    for (auto const& entity : mEntities)
    {
        if(gCoordinator->HasTag(entity) && !std::strcmp(gCoordinator->GetTag()[entity], "Player"))
        {
            // handle shooting input
            const Uint8* keystates = SDL_GetKeyboardState(NULL);
            
            auto& transform = gCoordinator->GetComponent<TransformComponent>(entity);
            
            if ( SDL_GetTicks() - mLastShootTime < mShootingInterval ){
                break;
            }
            
            if (keystates[SDL_SCANCODE_UP])
            {
                bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Up);
                mLastShootTime = SDL_GetTicks();
                break;
            }
            if (keystates[SDL_SCANCODE_DOWN])
            {
                bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Down);
                mLastShootTime = SDL_GetTicks();
                break;
            }
            if (keystates[SDL_SCANCODE_LEFT])
            {
                bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Left);
                mLastShootTime = SDL_GetTicks();
                break;
            }
            if (keystates[SDL_SCANCODE_RIGHT])
            {
                bulletSystem->SpawnBullet(gCoordinator, renderSystem,  renender, transform.x, transform.y, Right);
                mLastShootTime = SDL_GetTicks();
                break;
            }
        }
    }
}
