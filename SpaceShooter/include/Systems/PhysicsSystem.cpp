//
//  PhysicsSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#include <string>
#include "PhysicsSystem.hpp"
#include "../ECS/Coordinator.h"
#include "../Components/TransformComponent.h"
#include "../Components/MovementComponent.h"

extern Coordinator gCoordinator;

void PhysicsSystem::Init()
{

}

void PhysicsSystem::HandleInput(SDL_Event &e)
{
//    printf("%lu\n", mEntities.size());

    for (auto const& entity : mEntities)
    {
        if(gCoordinator.HasTag(entity) &&
           !std::strcmp(gCoordinator.GetTag()[entity], "Player"))
        {
            printf("processing player input\n");
        }else{
//            printf("%s\n",gCoordinator.GetTag()[entity]);
//            printf("%d\n", std::strcmp(gCoordinator.GetTag()[entity], "Player"));
        }
//        auto& movement = gCoordinator.GetComponent<MovementComponent>(entity);
    }
    
//    if( e.type == SDL_KEYDOWN && e.key.repeat == 0 )
//    {
//        switch( e.key.keysym.sym )
//        {
//            case SDLK_w: mVelY -= mVelValue; break;
//            case SDLK_s: mVelY += mVelValue; break;
//            case SDLK_a: mVelX -= mVelValue; break;
//            case SDLK_d: mVelX += mVelValue; break;
//        }
//    }
//    else if( e.type == SDL_KEYUP && e.key.repeat == 0 )
//    {
//        switch( e.key.keysym.sym )
//        {
//            case SDLK_w: mVelY += mVelValue; break;
//            case SDLK_s: mVelY -= mVelValue; break;
//            case SDLK_a: mVelX += mVelValue; break;
//            case SDLK_d: mVelX -= mVelValue; break;
//        }
//    }
}

void PhysicsSystem::Update()
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);
    }
}
