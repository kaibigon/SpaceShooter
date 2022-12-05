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


extern Coordinator gCoordinator;

void MovementSystem::Init()
{

}

void MovementSystem::HandleInput(SDL_Event &e)
{
//    printf("%lu\n", mEntities.size());

    for (auto const& entity : mEntities)
    {
        if(gCoordinator.HasTag(entity) &&
           !std::strcmp(gCoordinator.GetTag()[entity], "Player"))
        {
            auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);
            auto& movement = gCoordinator.GetComponent<MovementComponent>(entity);
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
//            printf("test: x:%d, y:%d\n", movement.velX, movement.velY);
        }else{
        }
    }
    
}

void MovementSystem::Update()
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);
        auto& movement = gCoordinator.GetComponent<MovementComponent>(entity);
        int last_x = transform.x;
        int last_y = transform.y;
        transform.x += movement.velX;
        transform.y += movement.velY;
        printf("test: x:%d, y:%d\n", last_x - transform.x, last_y - transform.y);
    }
    
}
