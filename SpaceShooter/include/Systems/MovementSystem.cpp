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

void MovementSystem::Update(std::shared_ptr<Coordinator>& gCoordinator, float deltaTime)
{
    for (auto const& entity : mEntities)
    {
        auto& transform = gCoordinator->GetComponent<TransformComponent>(entity);
        auto& movement = gCoordinator->GetComponent<MovementComponent>(entity);
        transform.x += (movement.velX * deltaTime);
        transform.y += (movement.velY * deltaTime);
    }
}
