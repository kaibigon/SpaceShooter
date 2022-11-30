//
//  PhysicsSystem.cpp
//  SpaceShooter
//
//  Created by Kai Wang on 2022/11/30.
//

#include "PhysicsSystem.hpp"
#include "../Coordinator.h"
#include "../components/TransformComponent.h"

extern Coordinator gCoordinator;

void PhysicsSystem::Init()
{
    printf("nmsl\n");
    printf("number: %lu\n", mEntities.size());
}

void PhysicsSystem::Update()
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator.GetComponent<TransformComponent>(entity);

        printf("x: %d, y: %d\n", transform.x, transform.y);
    }
}
