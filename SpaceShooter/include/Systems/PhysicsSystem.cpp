//
//  PhysicsSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#include "PhysicsSystem.hpp"
#include "../ECS/Coordinator.h"
#include "../Components/TransformComponent.h"

extern Coordinator gCoordinator;

void PhysicsSystem::Init()
{
}

void PhysicsSystem::Update()
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);

    }
}
