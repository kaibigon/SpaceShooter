//
//  PhysicsSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#include <string>
#include "MovementSystem.hpp"
#include "../ECS/Coordinator.h"
#include "../Components/Components.h"

void MovementSystem::Init()
{

}

// this should be in smh like inputSystem
void MovementSystem::HandleInput(std::shared_ptr<Coordinator>& gCoordinator, SDL_Event &e)
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

void MovementSystem::Update(std::shared_ptr<Coordinator>& gCoordinator, float deltaTime)
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator->GetComponent<TransformComponent>(entity);
        auto& movement = gCoordinator->GetComponent<MovementComponent>(entity);
//        printf("velx: %f, vely: %f\n", movement.velX * deltaTime, movement.velY * deltaTime);
        transform.x += (movement.velX * deltaTime);
        transform.y += (movement.velY * deltaTime);
    }
}
